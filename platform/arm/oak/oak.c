/*
 * Copyright 2014, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *    * Neither the name of Google Inc. nor the names of its
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <unistd.h>

#include "mosys/command_list.h"
#include "mosys/platform.h"

#include "drivers/google/cros_ec.h"

#include "lib/sku.h"

#include "oak.h"

static struct platform_cmd *oak_sub[] = {
	&cmd_ec,
	&cmd_memory,
	&cmd_platform,
	NULL
};

static struct platform_cb oak_cb = {
	.ec		= &cros_ec_cb,
	.memory		= &oak_memory_cb,
	.pd		= &cros_pd_cb,
	.sys		= &oak_sys_cb,
};

/* TODO(b/183045220): Remove after hana is migrated to unibuild */
#ifndef CONFIG_UNIBUILD
static const struct sku_info hana_sku_info = { .brand = "LEAO" };
#endif

static struct platform_intf platform_oak = {
	.type		= PLATFORM_ARMV8,
	.sub		= oak_sub,
	.cb		= &oak_cb,
#ifndef CONFIG_UNIBUILD
	.sku_info	= &hana_sku_info,
#endif
};
REGISTER_PLATFORM(platform_oak, "Oak");
