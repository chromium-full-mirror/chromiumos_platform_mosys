/* Copyright 2014 Google LLC
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
 *
 * fdt.c: Helper functions for getting data out of the device tree.
 */

#include <arpa/inet.h>
#include <errno.h>
#include <inttypes.h>
#include <string.h>

#include "lib/fdt.h"
#include "lib/file.h"

#include "mosys/alloc.h"
#include "mosys/log.h"
#include "mosys/mosys.h"
#include "mosys/platform.h"

#define FDT_ROOT "/proc/device-tree/"
/* FIXME: assume coreboot for now */
#define FDT_RAM_CODE_PATH FDT_ROOT "firmware/coreboot/ram-code"

#define LPDDR3_COMPAT_PATH FDT_ROOT "lpddr-channel0/rank@0/compatible"

static int fdt_get_uint32_val(const char *path, uint32_t *val)
{
	/* Leave room for a null-terminator in the buffer */
	char buf[sizeof(*val) + 1];

	if (read_file(path, buf, ARRAY_SIZE(buf), LOG_ERR) < 0)
		return -1;

	*val = ntohl(*(uint32_t *)buf);
	return 0;
}

int fdt_get_ram_code(uint32_t *ram_code)
{
	if (fdt_get_uint32_val(FDT_RAM_CODE_PATH, ram_code) < 0) {
		lprintf(LOG_ERR, "%s: Error when reading RAM code\n", __func__);
		return -1;
	}

	if (*ram_code == 0xffffffff) {
		lprintf(LOG_ERR, "%s: ram_code is invalid.\n", __func__);
		return -1;
	}

	lprintf(LOG_DEBUG, "%s: ram_code: %u\n", __func__, *ram_code);
	return 0;
}

int fdt_get_ram_ids(uint8_t *manufacturer_id, uint8_t *revision_id1,
		    uint8_t *revision_id2)
{
	char buf[32];

	if (read_file(LPDDR3_COMPAT_PATH, buf, sizeof(buf), LOG_ERR) <= 0) {
		lprintf(LOG_ERR, "%s: Error when reading Manufacturer ID\n",
			__func__);
		return -1;
	}

	/*
	 * Manufacturer ID is in ascii value gated between '-' and ','
	 * characters.  Revision ID is the hex number after the ','.
	 */
	if (sscanf(buf, "lpddr%*1d-%2hhx,%2hhx%2hhx", manufacturer_id,
		   revision_id1, revision_id2) != 3) {
		lprintf(LOG_ERR,
			"%s: Error when parsing Manufacturer/Revision ID\n",
			__func__);
		return -1;
	}

	lprintf(LOG_DEBUG,
		"%s: manufacturer_id: %#02x, revision_id: %#02x %#02x\n",
		__func__, *manufacturer_id, *revision_id1, *revision_id2);
	return 0;
}
