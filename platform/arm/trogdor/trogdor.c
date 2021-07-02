/* Copyright 2020 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "trogdor.h"
#include "drivers/google/cros_ec.h"
#include "lib/cros_config.h"
#include "lib/fdt.h"
#include "lib/sku.h"
#include "mosys/command_list.h"
#include "mosys/platform.h"
#include "mosys/intf_list.h"

static struct platform_cmd *trogdor_sub[] = {
	&cmd_ec,
	&cmd_memory,
	&cmd_pd,
	&cmd_platform,
	&cmd_eventlog,
	NULL
};

static int trogdor_probe(struct platform_intf *intf)
{
	return cros_config_probe(intf, NULL);
}

static struct platform_cb trogdor_cb = {
	.ec		= &cros_ec_cb,
	.memory		= &trogdor_memory_cb,
	.sys		= &fdt_sysinfo_cb,
};

static struct platform_intf platform_trogdor = {
	.type		= PLATFORM_ARMV8,
	.sub		= trogdor_sub,
	.cb		= &trogdor_cb,
	.probe		= &trogdor_probe,
};
REGISTER_PLATFORM(platform_trogdor, "Trogdor");
