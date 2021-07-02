/* Copyright 2020 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdlib.h>
#include <unistd.h>

#include "drivers/google/cros_ec.h"
#include "lib/cros_config.h"
#include "lib/file.h"
#include "lib/sku.h"
#include "mosys/command_list.h"
#include "mosys/platform.h"

#include "asurada.h"

static struct platform_cmd *asurada_sub[] = {
	&cmd_ec,
	&cmd_memory,
	&cmd_pd,
	&cmd_platform,
	&cmd_eventlog,
	NULL
};

static int asurada_probe(struct platform_intf *intf)
{
	return cros_config_probe(intf, NULL);
}

static struct platform_cb asurada_cb = {
	.ec		= &cros_ec_cb,
	.memory		= &asurada_memory_cb,
	.sys		= &asurada_sys_cb,
};

static struct platform_intf platform_asurada = {
	.type		= PLATFORM_ARMV8,
	.sub		= asurada_sub,
	.cb		= &asurada_cb,
	.probe		= &asurada_probe,
};
REGISTER_PLATFORM(platform_asurada, "Asurada");
