/* Copyright 2022 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "lib/fdt.h"
#include "lib/lpddr_ids.h"
#include "lib/nonspd.h"
#include "mosys/platform.h"
#include "herobrine.h"

/*
 * dimm_count  -  return total number of dimm slots
 *
 * @intf:       platform interface
 *
 * returns dimm slot count
 */
static int dimm_count(struct platform_intf *intf)
{
	return 1;
}

static int get_mem_info(struct platform_intf *intf, int dimm,
			const struct nonspd_mem_info **info)
{
	*info = lpddr_info_from_fdt_ids();

	if (*info)
		return 0;
	else
		return -1;
}

struct memory_cb herobrine_memory_cb = {
	.dimm_count = &dimm_count,
	.nonspd_mem_info = &get_mem_info,
};
