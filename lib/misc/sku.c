/**
 * Copyright 2017 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdlib.h>
#include <string.h>

#include "mosys/alloc.h"
#include "mosys/globals.h"
#include "mosys/log.h"
#include "mosys/platform.h"

#include "lib/file.h"
#include "lib/sku.h"
#include "lib/string.h"
#include "lib/vpd.h"

/*
 * Extracts the SERIES part from VPD "customization_id".
 *
 * customization_id should be in LOEMID-SERIES format.
 * If - is not found, return nothing.
 */
#ifndef CONFIG_UNIBUILD
static char *_extract_customization_id_series_part(void)
{
	char *customization_id;
	char *series = NULL, *dash;

	customization_id = vpd_get_value("customization_id");
	if (!customization_id)
		return NULL;

	dash = strchr(customization_id, '-');
	if (dash) {
		series = mosys_strdup(dash + 1);
	}
	free(customization_id);

	return series;
}
#endif

int sku_get_number(struct platform_intf *intf)
{
	if (!intf || !intf->cb || !intf->cb->sys) {
		return -1;
	}

	if (intf->cb->sys->sku_number) {
		return intf->cb->sys->sku_number(intf);
	}

	return -1;
}

char *sku_get_brand(struct platform_intf *intf)
{
	const struct sku_info *info = intf->sku_info;

	if (info && info->brand)
		return mosys_strdup(info->brand);

	return NULL;
}

char *sku_get_chassis(struct platform_intf *intf)
{
	char *result = NULL;

	result = sku_get_model(intf);
	if (result)
		strupper(result);
	return result;
}

char *sku_get_model(struct platform_intf *intf)
{
#ifdef CONFIG_UNIBUILD
	/*
	 * Right now, the longest model name is 13 characters.  64
	 * bytes is well in excess of what's necessary here.
	 */
	char model_buf[64];

	if (read_file("/run/chromeos-config/v1/name", model_buf,
		      sizeof(model_buf), LOG_ERR) < 0) {
		lprintf(LOG_ERR,
			"%s: Failed to read model from chromeos-config\n",
			__func__);
		return NULL;
	}

	return mosys_strdup(model_buf);
#else
	const struct sku_info *info = intf->sku_info;
	char *result = NULL;

	if (info && info->model)
		return mosys_strdup(info->model);

	/* First try customization_id (go/cros-chassis-id). */
	result = _extract_customization_id_series_part();
	if (!result && intf->name)
		result = mosys_strdup(intf->name);
	if (result)
		strlower(result);
	return result;
#endif
}

char *sku_get_customization(struct platform_intf *intf)
{
	const struct sku_info *info = intf->sku_info;
	char *customization_id;

	/* Look for model first before looking into VPD */
	if (info && info->customization)
		return mosys_strdup(info->customization);

	customization_id = vpd_get_value("customization_id");
	if (customization_id)
		return customization_id;

	return NULL;
}
