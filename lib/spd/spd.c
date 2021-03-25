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
 *
 * DIMM Serial Presence Detect interface normal access is via I2C but some
 * platforms hide SPD behind memory controller and other access method must be
 * used.
 */

#include <stdlib.h>

#include "mosys/alloc.h"
#include "mosys/log.h"
#include "mosys/platform.h"

#include "lib/math.h"
#include "lib/spd.h"

/* new_spd_device() - create a new instance of spd_device
 *
 * @intf:  platform_intf for access
 * @dimm:  Google logical dimm number to represent
 *
 * returns allocated and filled in spd_devices on success, NULL if error
 */
struct spd_device *new_spd_device(struct platform_intf *intf, int dimm)
{
	struct spd_device *spd;

	if (intf == NULL || dimm < 0) {
		return NULL;
	}

	spd = mosys_malloc(sizeof(*spd));
	spd->dimm_num = dimm;
	memset(&spd->eeprom.data[0], 0xff, SPD_MAX_LENGTH);

	if (intf->cb->memory->spd->read(intf, dimm, 0, 3,
	                                &spd->eeprom.data[0]) != 3) {
		free(spd);
		return NULL;
	}

	spd->dram_type = (enum spd_dram_type)spd->eeprom.data[2];
	spd->eeprom.length = spd_total_size(&spd->eeprom.data[0]);

	/* Invalid length. */
	if (spd->eeprom.length <= 0) {
		lperror(LOG_DEBUG, "Invalid DIMM(%d) SPD length(%d).\n",
		        dimm, spd->eeprom.length);
		free(spd);
		return NULL;
	}

	/* Fill in copy of SPD eeprom area. */
	if (intf->cb->memory->spd->read(intf, dimm, 0,
	                                spd->eeprom.length,
	                                &spd->eeprom.data[0])
			!= spd->eeprom.length) {
		lperror(LOG_DEBUG,
		        "Unable to read full contents of SPD from DIMM %d.\n",
		        dimm);
		free(spd);
		return NULL;
	}

	return spd;
}
