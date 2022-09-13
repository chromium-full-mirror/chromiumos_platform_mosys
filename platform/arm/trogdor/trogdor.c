/* Copyright 2020 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "trogdor.h"
#include "drivers/google/cros_ec.h"
#include "lib/fdt.h"
#include "lib/sku.h"
#include "mosys/command_list.h"
#include "mosys/platform.h"

static struct platform_cmd *trogdor_sub[] = {
	&cmd_ec,
	&cmd_memory,
	&cmd_pd,
	&cmd_platform,
	NULL
};

static struct platform_cb trogdor_cb = {
	.ec		= &cros_ec_cb,
	.memory		= &trogdor_memory_cb,
	.sys		= &fdt_sysinfo_cb,
};

static struct platform_intf platform_trogdor = {
	.type		= PLATFORM_ARMV8,
	.sub		= trogdor_sub,
	.cb		= &trogdor_cb,
};
REGISTER_PLATFORM(platform_trogdor, "Trogdor");
