/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdlib.h>
#include <unistd.h>

#include "drivers/google/cros_ec.h"
#include "lib/cros_config.h"
#include "lib/fdt.h"
#include "lib/sku.h"
#include "mosys/command_list.h"
#include "mosys/platform.h"

#include "cherry.h"

static struct platform_cmd *cherry_sub[] = {
	&cmd_ec,
	&cmd_memory,
	&cmd_pd,
	&cmd_platform,
	NULL
};

static int cherry_probe(struct platform_intf *intf)
{
	return cros_config_probe(intf, NULL);
}

static struct platform_cb cherry_cb = {
	.ec		= &cros_ec_cb,
	.memory		= &cherry_memory_cb,
	.sys		= &fdt_sysinfo_cb,
};

static struct platform_intf platform_cherry = {
	.type		= PLATFORM_ARMV8,
	.sub		= cherry_sub,
	.cb		= &cherry_cb,
	.probe		= &cherry_probe,
};
REGISTER_PLATFORM(platform_cherry, "Cherry");
