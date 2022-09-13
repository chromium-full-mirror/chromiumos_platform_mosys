/* Copyright 2020 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdlib.h>
#include <unistd.h>

#include "drivers/google/cros_ec.h"
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
	NULL
};

static struct platform_cb asurada_cb = {
	.ec		= &cros_ec_cb,
	.memory		= &asurada_memory_cb,
	.sys		= &asurada_sys_cb,
};

static struct platform_intf platform_asurada = {
	.type		= PLATFORM_ARMV8,
	.sub		= asurada_sub,
	.cb		= &asurada_cb,
};
REGISTER_PLATFORM(platform_asurada, "Asurada");
