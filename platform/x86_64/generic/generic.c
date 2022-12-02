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
	&cmd_platform,
	NULL,
};

static struct platform_cb generic_x86_cb = {
	.ec = &cros_ec_cb,
	.memory = &smbios_memory_cb,
};

/*
 * Macro to register this platfom under many names.
 *
 * Ideally, we can get everything under the "Generic" name one day,
 * but many external services (e.g., Tast) have started relying on
 * Mosys' internal platform names for selecting tests.  Thus, we
 * duplicate the platform under many different names where required.
 */
#define REGISTER_ALIAS(name) _register_alias_1(name, __LINE__)
#define _register_alias_1(name, line) _register_alias_2(name, line)
#define _register_alias_2(name, line)                   \
	static struct platform_intf platform_##line = { \
		.type = PLATFORM_X86_64,                \
		.sub = subcommands,                     \
		.cb = &generic_x86_cb,                  \
	};                                              \
	REGISTER_PLATFORM(platform_##line, name)

REGISTER_ALIAS("Generic");

/*
 * Legacy platform aliases prior to "Generic" being created.
 *
 * DO NOT APPEND NEW NAMES TO THIS LIST.  Instead, you should set the
 * mosys platform name to "Generic" in your Boxster or model.yaml
 * configuration.
 */
REGISTER_ALIAS("Asuka");
REGISTER_ALIAS("Caroline");
REGISTER_ALIAS("Cave");
REGISTER_ALIAS("Chell");
REGISTER_ALIAS("Coral");
REGISTER_ALIAS("Dedede");
REGISTER_ALIAS("Fizz");
REGISTER_ALIAS("Grunt");
REGISTER_ALIAS("Hatch");
REGISTER_ALIAS("Kalista");
REGISTER_ALIAS("Lars");
REGISTER_ALIAS("Octopus");
REGISTER_ALIAS("Poppy");
REGISTER_ALIAS("Puff");
REGISTER_ALIAS("Reef");
REGISTER_ALIAS("Sentry");
REGISTER_ALIAS("Volteer");
REGISTER_ALIAS("Zork");
