/* Copyright 2021 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stddef.h>

#include "mosys/command_list.h"
#include "mosys/platform.h"
#include "herobrine.h"

/* TODO(b:177917361): Add &cmd_memory */
static struct platform_cmd *herobrine_sub[] = {
	&cmd_memory,
	NULL,
};

/* TODO(b:177917361): add .memory */
static struct platform_cb herobrine_cb = {
	.memory = &herobrine_memory_cb,
};

static struct platform_intf platform_herobrine = {
	.type = PLATFORM_ARMV8,
	.sub = herobrine_sub,
	.cb = &herobrine_cb,
};
REGISTER_PLATFORM(platform_herobrine, "Herobrine");
