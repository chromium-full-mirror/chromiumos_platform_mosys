/*
 * Copyright 2013 Google LLC
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
 *    * Neither the name of Google LLC nor the names of its
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

#include "lib/memory.h"
#include "lib/sku.h"

#include "mosys/alloc.h"
#include "mosys/command_list.h"
#include "mosys/log.h"
#include "mosys/platform.h"

static struct platform_cmd *glados_sub[] = {
	&cmd_memory,
	&cmd_platform,
	NULL
};

static struct platform_cb glados_cb = {
	.memory		= &smbios_memory_cb,
};

static const struct sku_info asuka_sku_info = { .brand = "DEAH" };
static struct platform_intf platform_asuka = {
	.type = PLATFORM_X86_64,
	.sub = glados_sub,
	.cb = &glados_cb,
	.sku_info = &asuka_sku_info,
};
REGISTER_PLATFORM(platform_asuka, "Asuka");

static const struct sku_info caroline_sku_info = { .brand = "SMAK" };
static struct platform_intf platform_caroline = {
	.type = PLATFORM_X86_64,
	.sub = glados_sub,
	.cb = &glados_cb,
	.sku_info = &caroline_sku_info,
};
REGISTER_PLATFORM(platform_caroline, "Caroline");

static const struct sku_info chell_sku_info = { .brand = "HPZR" };
static struct platform_intf platform_chell = {
	.type = PLATFORM_X86_64,
	.sub = glados_sub,
	.cb = &glados_cb,
	.sku_info = &chell_sku_info,
};
REGISTER_PLATFORM(platform_chell, "Chell");
