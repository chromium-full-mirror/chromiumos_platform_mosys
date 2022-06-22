/*
 * Copyright 2013, Google Inc.
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

#include "lib/memory.h"
#include "lib/probe.h"

#include "mosys/alloc.h"
#include "mosys/command_list.h"
#include "mosys/log.h"
#include "mosys/platform.h"

#include "drivers/google/cros_ec.h"

#include "strago.h"

static const char *const probe_id_list[] = {
	"Banon",
	"Celes",
	"Cyan",
	"Edgar",
	"Kefka",
	"Reks",
	"Relm",
	"Setzer",
	"Strago",
	"Terra",
	"Ultima",
	"Umaro",
	"Wizpig",
	NULL,
};

static struct platform_cmd *strago_sub[] = {
	&cmd_ec,
	&cmd_memory,
	&cmd_platform,
	NULL
};

static int strago_setup(struct platform_intf *intf)
{
	const char *const *pid;

	for (pid = probe_id_list; pid && *pid; pid++) {
		if (probe_smbios(intf, *pid)) {
			/* Update canonical platform name */
			intf->name = *pid;
			return 0;
		}
	}

	return -1;
}

static struct platform_cb strago_cb = {
	.ec		= &cros_ec_cb,
	.memory		= &smbios_memory_cb,
	.sys 		= &strago_sys_cb,
};

static struct platform_intf platform_strago = {
	.type		= PLATFORM_X86_64,
	.sub		= strago_sub,
	.cb		= &strago_cb,
	.setup		= &strago_setup,
};
REGISTER_PLATFORM(platform_strago, "Strago");
