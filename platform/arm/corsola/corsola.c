/* Copyright 2022 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdlib.h>
#include <unistd.h>

#include "drivers/google/cros_ec.h"
#include "lib/fdt.h"
#include "lib/sku.h"
#include "mosys/command_list.h"
#include "mosys/platform.h"

static struct platform_cmd *corsola_sub[] = {
	&cmd_ec,
	&cmd_pd,
	&cmd_platform,
	NULL
};

/* TODO:(yidilin) add .memory */
static struct platform_cb corsola_cb = {
	.ec	= &cros_ec_cb,
	.sys	= &fdt_sysinfo_cb,
};

static struct platform_intf platform_corsola = {
	.type	= PLATFORM_ARMV8,
	.sub	= corsola_sub,
	.cb	= &corsola_cb,
};

REGISTER_PLATFORM(platform_corsola, "Corsola");
