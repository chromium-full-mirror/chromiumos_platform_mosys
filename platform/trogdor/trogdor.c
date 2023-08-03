/* Copyright 2020 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stddef.h>

#include "trogdor.h"
#include "mosys/command_list.h"
#include "mosys/platform.h"

static struct platform_cmd *trogdor_sub[] = {
	&cmd_memory,
	NULL,
};

static struct platform_cb trogdor_cb = {
	.memory = &trogdor_memory_cb,
};

static struct platform_intf platform_trogdor = {
	.type = PLATFORM_ARMV8,
	.sub = trogdor_sub,
	.cb = &trogdor_cb,
};
REGISTER_PLATFORM(platform_trogdor, "Trogdor");
