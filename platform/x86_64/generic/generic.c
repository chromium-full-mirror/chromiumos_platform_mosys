/* Copyright 2021 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * Most modern x86 developments can be supported by common code which
 * assumes the following:
 *
 * - Unibuild
 * - We have a Chrome OS EC
 * - Memory information is available in SMBIOS
 *
 * This implements a common platform_intf for all devices which that
 * applies to.
 */

#include <stdlib.h>

#include "drivers/google/cros_ec.h"
#include "lib/memory.h"
#include "lib/smbios.h"
#include "mosys/command_list.h"
#include "mosys/platform.h"

static struct platform_cmd *subcommands[] = {
	&cmd_ec,
	&cmd_memory,
	&cmd_pd,
	NULL,
};

static struct platform_cb generic_x86_cb = {
	.ec = &cros_ec_cb,
	.memory = &smbios_memory_cb,
};

static struct platform_intf platform_generic = {
	.type = PLATFORM_X86_64,
	.sub = subcommands,
	.cb = &generic_x86_cb,
};
REGISTER_PLATFORM(platform_generic, "Generic");
