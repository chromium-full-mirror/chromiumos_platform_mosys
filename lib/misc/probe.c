/* Copyright 2012, Google Inc.
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

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "mosys/globals.h"
#include "mosys/log.h"
#include "mosys/platform.h"

#include "lib/fdt.h"
#include "lib/file.h"
#include "lib/math.h"
#include "lib/probe.h"
#include "lib/smbios.h"
#include "lib/string.h"

int probe_smbios(struct platform_intf *intf, const char *name)
{
	static char *id = NULL;
	int ret = 0;

	if (id)
		goto probe_smbios_cmp;

	/* TODO(jrosenth): getting the product name does not actually
	   require the platform_intf.  Remove this from
	   smbios_sysinfo_get_name and clean up all probe_smbios calls
	   to not pass intf. */
	id = smbios_sysinfo_get_name(intf);

probe_smbios_cmp:
	if (!id) {
		ret = 0;
		lprintf(LOG_SPEW, "%s: cannot find product name\n", __func__);
	} else if (!strcmp(id, name)) {
		ret = 1;
		lprintf(LOG_DEBUG, "%s: matched id \"%s\"\n", __func__, id);
	}
	return ret;
}

#define FDT_COMPATIBLE "/proc/device-tree/compatible"
int probe_fdt_compatible(const char * const id_list[], int num_ids,
			 int allow_partial)
{
	int ret = -1, i, fd;
	char compat[64];	/* arbitrarily chosen max size */
	char *p;

	lprintf(LOG_DEBUG, "Probing platform with FDT compatible node\n");

	fd = file_open(FDT_COMPATIBLE, FILE_READ);
	if (fd < 0) {
		lprintf(LOG_DEBUG, "Cannot open %s\n", FDT_COMPATIBLE);
		return -1;
	}

	/*
	 * Device tree "compatible" data consists of a list of comma-separated
	 * pairs with a NULL after each pair. For example, "foo,bar\0bam,baz\0"
	 * is foo,bar and bam,baz.
	 */
	p = &compat[0];
	while (read(fd, p, 1) == 1) {
		if (*p != 0) {
			p++;
			if (p - &compat[0] > sizeof(compat)) {
				lprintf(LOG_ERR,
					"FDT compatible identifier too long\n");
				goto probe_fdt_compatible_exit;
			}
			continue;
		}

		for (i = 0; (i < num_ids) && id_list[i]; i++) {
			int cmp = 0;

			lprintf(LOG_DEBUG, "\t\"%s\" == \"%s\" ? ",
					&compat[0], id_list[i]);

			if (allow_partial) {
				cmp = strncmp(&compat[0],
					id_list[i], strlen(id_list[i]));
			} else {
				cmp = strcmp(&compat[0], id_list[i]);
			}

			if (!cmp) {
				lprintf(LOG_DEBUG, "yes\n");
				ret = i;
				goto probe_fdt_compatible_exit;
			} else {
				lprintf(LOG_DEBUG, "no\n");
			}
		}

		p = &compat[0];
	}

probe_fdt_compatible_exit:
	close(fd);
	return ret;
}
