/* Copyright 2023 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdlib.h>
#include <unistd.h>

#include "mosys/command_list.h"
#include "mosys/platform.h"

#include "geralt.h"

static struct platform_cmd *geralt_sub[] = {
	&cmd_memory,
	NULL,
};

static struct platform_cb geralt_cb = {
	.memory = &geralt_memory_cb,
};

static struct platform_intf platform_geralt = {
	.type = PLATFORM_ARMV8,
	.sub = geralt_sub,
	.cb = &geralt_cb,
};

REGISTER_PLATFORM(platform_geralt, "Geralt");
