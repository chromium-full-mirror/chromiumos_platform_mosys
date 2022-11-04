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

#ifndef CONFIG_UNIBUILD
char *sku_get_brand(struct platform_intf *intf)
{
	const struct sku_info *info = intf->sku_info;

	if (info && info->brand)
		return mosys_strdup(info->brand);

	return NULL;
}

char *sku_get_model(struct platform_intf *intf)
{
	const struct sku_info *info = intf->sku_info;
	char *result = NULL;

	if (info && info->model)
		return mosys_strdup(info->model);

	if (intf->name) {
		result = mosys_strdup(intf->name);
		strlower(result);
	}

	return result;
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
#endif
