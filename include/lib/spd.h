/*
 * Copyright 2012, Google Inc.
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
 * Serial Presence Detect (SPD) code for access of SPDs on DIMMs.
 */

#ifndef LIB_SPD_H__
#define LIB_SPD_H__

#include <inttypes.h>

#include "lib/ddr4.h"
#include "lib/val2str.h"

#define SPD_DEFAULT_LENGTH 256
#define SPD_DDR4_LENGTH    512
#define SPD_MAX_LENGTH     SPD_DDR4_LENGTH

#define SPD_PAGE_0        (0x6C >> 1)
#define SPD_PAGE_1        (0x6E >> 1)

/* forward declarations */
struct kv_pair;
struct platform_intf;

/* different types of DRAM (fundamental memory type) for SPD */
enum spd_dram_type {
	SPD_DRAM_TYPE_DDR3	= 0x0b,
	SPD_DRAM_TYPE_LPDDR3	= 0xf1,
	SPD_DRAM_TYPE_JEDEC_LPDDR3 = 0x0f,
	SPD_DRAM_TYPE_DDR4      = 0x0c,
	SPD_DRAM_TYPE_LPDDR4	= 0x10,
	SPD_DRAM_TYPE_LPDDR4X	= 0x11,
};

enum ddr3_module_type {
	DDR3_MODULE_TYPE_UNDEFINED = 0,
	DDR3_MODULE_TYPE_RDIMM,
	DDR3_MODULE_TYPE_UDIMM,
	DDR3_MODULE_TYPE_SO_DIMM,
	DDR3_MODULE_TYPE_MICRO_DIMM,
	DDR3_MODULE_TYPE_MINI_RDIMM,
	DDR3_MODULE_TYPE_MINI_UDIMM,
	DDR3_MODULE_TYPE_MINI_CDIMM,
	DDR3_MODULE_TYPE_72b_SO_UDIMM,
	DDR3_MODULE_TYPE_72b_SO_RDIMM,
	DDR3_MODULE_TYPE_72b_SO_CDIMM,
	DDR3_MODULE_TYPE_LRDIMM,
};

static const struct valstr ddr3_module_type_lut[] = {
	{ DDR3_MODULE_TYPE_UNDEFINED, "Undefined" },
	{ DDR3_MODULE_TYPE_RDIMM, "RDIMM" },
	{ DDR3_MODULE_TYPE_UDIMM, "UDIMM" },
	{ DDR3_MODULE_TYPE_SO_DIMM, "SO-DIMM" },
	{ DDR3_MODULE_TYPE_MICRO_DIMM, "MICRO-DIMM" },
	{ DDR3_MODULE_TYPE_MINI_RDIMM, "MINI-RDIMM" },
	{ DDR3_MODULE_TYPE_MINI_UDIMM, "MINI-UDIMM" },
	{ DDR3_MODULE_TYPE_MINI_CDIMM, "MINI-CDIMM" },
	{ DDR3_MODULE_TYPE_72b_SO_UDIMM, "72b-SO-UDIMM" },
	{ DDR3_MODULE_TYPE_72b_SO_RDIMM, "72b-SO-RDIMM" },
	{ DDR3_MODULE_TYPE_72b_SO_CDIMM, "72b-SO-CDIMM" },
	{ DDR3_MODULE_TYPE_LRDIMM, "LRDIMM" },
};

struct spd_eeprom {
	int length;
	uint8_t data[SPD_MAX_LENGTH];
};

struct spd_device {
	int dimm_num; /* DIMM number in system. */
	enum spd_dram_type dram_type; /* Fundamental DRAM type. */
	struct spd_eeprom eeprom;
};

/*
 * various SPD fields that can be retrieved
 * these are found in different locations on DDR/DDR2 vs. FBDIMM
 */
enum spd_field_type {
	SPD_GET_DRAM_TYPE,      /* DRAM type */
	SPD_GET_MODULE_TYPE,    /* DIMM type */
	SPD_GET_MFG_ID,		/* Module Manufacturer ID */
	SPD_GET_MFG_ID_DRAM,	/* DRAM Manufacturer ID */
	SPD_GET_MFG_LOC,	/* Module Manufacturing Location */
	SPD_GET_MFG_DATE,	/* Module Manufacturing Date */
	SPD_GET_PART_NUMBER,	/* Module Part Number */
	SPD_GET_REVISION_CODE,	/* Module Revision Code */
	SPD_GET_SIZE,		/* Module Size (in MB) */
	SPD_GET_ECC,		/* ECC capable: boolean */
	SPD_GET_RANKS,		/* Number of ranks */
	SPD_GET_WIDTH,		/* SDRAM device width */
	SPD_GET_CHECKSUM,	/* SPD checksum */
};

/*
 * new_spd_device() - create a new instance of spd_device
 *
 * @intf:  platform_intf for access
 * @dimm:  Google logical dimm number to represent
 *
 * returns allocated and filled in spd_devices on success, NULL if error
 */
extern struct spd_device *new_spd_device(struct platform_intf *intf, int dimm);

/* add register to key=value pair */
extern int spd_print_reg(struct platform_intf *intf,
			 struct kv_pair *kv, const void *data, uint8_t reg);

/* add field to key=value pair */
extern int spd_print_field(struct platform_intf *intf,
			   struct kv_pair *kv,
			   const void *data, enum spd_field_type type);

/* print raw spd */
extern int spd_print_raw(struct kv_pair *kv, int len, uint8_t *data);

/*
 * spd_total_size  -  determine total bytes in spd from first few bytes
 *
 * @data:	spd data
 *
 * returns total size of SPD, may be less than max depending on type of module
 * returns <0 to indicate failure
 *
 */
extern int spd_total_size(uint8_t *data);

/*
 * spd_print_field_ddr3  -  add common DDR SPD fields into key=value pair
 *
 * @intf:       platform interface
 * @kv:         key=value pair
 * @data:       raw spd data
 * @type:       type of field to retrieve
 *
 * returns 1 to indicate data added to key=value pair
 * returns 0 to indicate no data added
 * returns <0 to indicate error
 *
 */
extern int spd_print_field_ddr3(struct platform_intf *intf, struct kv_pair *kv,
                                const void *data, enum spd_field_type type);

#endif /* LIB_SPD_H__ */
