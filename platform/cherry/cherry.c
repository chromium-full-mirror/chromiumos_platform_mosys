/* Copyright 2021 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdlib.h>
#include <unistd.h>

#include "mosys/command_list.h"
#include "mosys/platform.h"

#include "cherry.h"

static struct platform_cmd *cherry_sub[] = {
	&cmd_memory,
	NULL,
};

static struct platform_cb cherry_cb = {
	.memory = &cherry_memory_cb,
};

static struct platform_intf platform_cherry = {
	.type = PLATFORM_ARMV8,
	.sub = cherry_sub,
	.cb = &cherry_cb,
};
REGISTER_PLATFORM(platform_cherry, "Cherry");
