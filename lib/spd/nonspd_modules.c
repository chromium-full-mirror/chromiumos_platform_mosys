/*
 * Copyright 2015, Google Inc.
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

#include "lib/nonspd_modules.h"

/* Common manufacturing IDs */
#define MFGID_ELPIDA	{ .msb = 0x2c, .lsb = 0x80 }
#define MFGID_HYNIX	{ .msb = 0xad, .lsb = 0x80 }
#define MFGID_MICRON	{ .msb = 0x2c, .lsb = 0x00 }
#define MFGID_NANYA	{ .msb = 0x0b, .lsb = 0x03 }
#define MFGID_SAMSUNG	{ .msb = 0xce, .lsb = 0x00 }
#define MFGID_SANDISK	{ .msb = 0x45, .lsb = 0x00 }

const struct nonspd_mem_info elpida_lpddr3_edfa164a2ma_jd_f = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_UNDEFINED,

        .module_size_mbits      = 8192,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800, DDR_933 },

        .module_mfg_id          = MFGID_ELPIDA,
        .dram_mfg_id            = MFGID_ELPIDA,

        .part_num               =
                { 'E', 'D', 'F', 'A', '1', '6', '4', 'A', '2', 'M', 'A', '-',
                  'J', 'D', '-', 'F',},
};

const struct nonspd_mem_info elpida_lpddr3_f8132a3ma_gd_f = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_UNDEFINED,

        .module_size_mbits      = 8192,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

        .module_mfg_id          = MFGID_ELPIDA,
        .dram_mfg_id            = MFGID_ELPIDA,

        .part_num               =
                { 'F', '8', '1', '3', '2', 'A', '3', 'M', 'A', '-', 'G', 'D',
                  '-', 'F',},
};

const struct nonspd_mem_info elpida_lpddr3_fa232a2ma_gc_f = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_UNDEFINED,

        .module_size_mbits      = 16384,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

        .module_mfg_id          = MFGID_ELPIDA,
        .dram_mfg_id            = MFGID_ELPIDA,

        .part_num               =
                { 'F', 'A', '2', '3', '2', 'A', '2', 'M', 'A', '-', 'G', 'C',
                  '-', 'F',},
};

const struct nonspd_mem_info hynix_ddr3l_h5tc4g63afr_pba = {
        .dram_type              = SPD_DRAM_TYPE_DDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

        .module_size_mbits      = 4096,
        .num_ranks              = 1,
        .device_width           = 16,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .serial_num             = { 0, 0, 0, 0 },
        .part_num               =
                { 'H', '5', 'T', 'C', '4', 'G', '6', '3', 'A', 'F', 'R', '-',
                  'P', 'B', 'A'},
};

const struct nonspd_mem_info hynix_ddr3l_h5tc4g63cfr_pba = {
        .dram_type              = SPD_DRAM_TYPE_DDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

        .module_size_mbits      = 4096,
        .num_ranks              = 1,
        .device_width           = 16,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .serial_num             = { 0, 0, 0, 0 },
        .part_num               =
                { 'H', '5', 'T', 'C', '4', 'G', '6', '3', 'C', 'F', 'R', '-',
                  'P', 'B', 'A'},
};

const struct nonspd_mem_info hynix_ddr3l_h5tc4g63efr_rda = {
        .dram_type              = SPD_DRAM_TYPE_DDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_UNDEFINED,

        .module_size_mbits      = 4096,
        .num_ranks              = 1,
        .device_width           = 16,
        .ddr_freq               = { DDR_400, DDR_533, DDR_667, DDR_800, DDR_933 },

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .serial_num             = { 0, 0, 0, 0 },
        .part_num               =
                { 'H', '5', 'T', 'C', '4', 'G', '6', '3', 'E', 'F', 'R', '-',
                  'R', 'D', 'A'},
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnn8gtmlar_nud = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

        .module_size_mbits      = 8192,
        .num_ranks              = 1,
        .device_width           = 32,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .part_num               =
                { 'H', '9', 'C', 'C', 'N', 'N', 'N', '8', 'G', 'T', 'M', 'L',
                  'A', 'R', '-', 'N', 'U', 'D',},
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbjtalar_nud = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

        .module_size_mbits      = 16384,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .part_num               =
                { 'H', '9', 'C', 'C', 'N', 'N', 'N', 'B', 'J', 'T', 'A', 'L',
                  'A', 'R', '-', 'N', 'U', 'D',},
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbjtmlar_nud = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

        .module_size_mbits      = 16384,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .part_num               =
                { 'H', '9', 'C', 'C', 'N', 'N', 'N', 'B', 'J', 'T', 'M', 'L',
                  'A', 'R', '-', 'N', 'U', 'D',},
};

const struct nonspd_mem_info hynix_ddr3l_h5tc8g63amr_pba = {
	.dram_type              = SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,
	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 16,
	.ddr_freq 		= { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

	.module_mfg_id		= MFGID_HYNIX,
	.dram_mfg_id		= MFGID_HYNIX,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		=
		{ 'H', '5', 'T', 'C', '8', 'G', '6', '3', 'A', 'M', 'R', '-',
		  'P', 'B', 'A' },
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbptblbr_nud = {
	.dram_type              = SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits      = 16384,
	.num_ranks              = 2,
	.device_width           = 32,
	.ddr_freq               = { DDR_667, DDR_800, DDR_933 },

	.module_mfg_id          = MFGID_HYNIX,
	.dram_mfg_id            = MFGID_HYNIX,

	.part_num =
		{ 'H', '9', 'C', 'C', 'N', 'N', 'N', 'B', 'P', 'T', 'B', 'L',
		  'B', 'R', '-', 'N', 'U', 'D',},
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbltblar_nud = {
	.dram_type              = SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits      = 16384,
	.num_ranks              = 2,
	.device_width           = 32,
	.ddr_freq               = { DDR_667, DDR_800, DDR_933 },

	.module_mfg_id          = MFGID_HYNIX,
	.dram_mfg_id            = MFGID_HYNIX,

	.part_num =
		{ 'H', '9', 'C', 'C', 'N', 'N', 'N', 'B', 'L', 'T', 'B', 'L',
		  'A', 'R', '-', 'N', 'U', 'D',},
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbktmlbr_ntd = {
	.dram_type              = SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits      = 16384,
	.num_ranks              = 2,
	.device_width           = 32,
        .ddr_freq               = { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

	.module_mfg_id          = MFGID_HYNIX,
	.dram_mfg_id            = MFGID_HYNIX,

	.part_num =
		{ 'H', '9', 'C', 'C', 'N', 'N', 'N', 'B', 'K', 'T', 'M', 'L',
		  'B', 'R', '-', 'N', 'T', 'D',},
};

const struct nonspd_mem_info hynix_lpddr4_h9hcnnn8kumlhr = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR4,

        .module_size_mbits      = 8192,
        .num_ranks              = 1,
        .device_width           = 32,
        .ddr_freq               = { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .part_num =
                { 'H', '9', 'H', 'C', 'N', 'N', 'N', '8', 'K', 'U', 'M', 'L',
                  'H', 'R',},
};

const struct nonspd_mem_info hynix_lpddr4_h9hcnnnbpumlhr = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR4,

        .module_size_mbits      = 16384,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .part_num =
                { 'H', '9', 'H', 'C', 'N', 'N', 'N', 'B', 'P', 'U', 'M', 'L',
                  'H', 'R',},
};

const struct nonspd_mem_info hynix_lpddr4x_h9hcnnncpmalhr_nee = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR4X,

        .module_size_mbits      = 32768,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_800, DDR_1200, DDR_1600 },

        .module_mfg_id          = MFGID_HYNIX,
        .dram_mfg_id            = MFGID_HYNIX,

        .part_num =
                { 'H', '9', 'H', 'C', 'N', 'N', 'N', 'C', 'P', 'M', 'A', 'L',
                  'H', 'R', '-', 'N', 'E', 'E'},
};

const struct nonspd_mem_info hynix_lpddr4x_h54g56cyrbx247 = {
	.dram_type              = SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits      = 32768,
	.num_ranks              = 2,
	.device_width           = 32,

	.module_mfg_id          = MFGID_HYNIX,
	.dram_mfg_id            = MFGID_HYNIX,

	.part_num               = "H54G56CYRBX247",
};

const struct nonspd_mem_info hynix_lpddr4x_h9hcnnncpmmlxr_nee = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq		= { DDR_800, DDR_1200, DDR_1600 },

	.module_mfg_id		= MFGID_HYNIX,
	.dram_mfg_id		= MFGID_HYNIX,

	.part_num =
                { 'H', '9', 'H', 'C', 'N', 'N', 'N', 'C', 'P', 'M', 'M', 'L',
                  'X', 'R', '-', 'N', 'E', 'E'},
};

const struct nonspd_mem_info hynix_lpddr4x_h9hcnnnfammlxr_nee = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	=  65536,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq		= { DDR_800, DDR_1200, DDR_1600 },

	.module_mfg_id		= MFGID_HYNIX,
	.dram_mfg_id		= MFGID_HYNIX,

	.part_num =
				{ 'H', '9', 'H', 'C', 'N', 'N', 'N', 'F', 'A', 'M', 'M', 'L',
				  'X', 'R', '-', 'N', 'E', 'E' },
};

const struct nonspd_mem_info hynix_lpddr4x_h54g68cyrbx248 = {
	.dram_type              = SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits      =  65536,
	.num_ranks              = 2,
	.device_width           = 32,

	.module_mfg_id          = MFGID_HYNIX,
	.dram_mfg_id            = MFGID_HYNIX,

	.part_num               = "H54G68CYRBX248",
};

const struct nonspd_mem_info micron_mt41k256m16ha = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	.ddr_freq 		= { DDR_533, DDR_667, DDR_800 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		= { 'M', 'T', '4', '1', 'K', '2', '5', '6', 'M',
				    '1', '6', 'H', 'A', '-', '1', '2', '5' },
};

const struct nonspd_mem_info micron_mt52l256m32d1pf = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq 		= { DDR_800, DDR_933, DDR_1067 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		= { 'M', 'T', '5', '2', 'L', '2', '5', '6', 'M',
				    '3', '2', 'D', '1', 'P', 'F', '-', '0', '9',
				    '3', 'W', 'T', ':', 'B' },
};

const struct nonspd_mem_info micron_mt52l512m32d2pf = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_800, DDR_933, DDR_1067 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		= { 'M', 'T', '5', '2', 'L', '5', '1', '2', 'M',
				    '3', '2', 'D', '2', 'P', 'F', '-', '0', '9',
				    '3', 'W', 'T', ':', 'B' },
};

const struct nonspd_mem_info nanya_ddr3l_nt5cc256m16dp_di = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	/* CL = 11, CWL = 8, min = 1.25ns, max <1.5ns */
	.ddr_freq 		= { DDR_667, DDR_800 },
	.module_mfg_id		= MFGID_NANYA,
	.dram_mfg_id		= MFGID_NANYA,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		= { 'N', 'T', '5', 'C', 'C', '2', '5', '6',
				    'M', '1', '6', 'D', 'P', '-', 'D', 'I' },
};

const struct nonspd_mem_info nanya_ddr3l_nt5cc256m16er_ek = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800, DDR_933 },
	.module_mfg_id		= MFGID_NANYA,
	.dram_mfg_id		= MFGID_NANYA,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		= { 'N', 'T', '5', 'C', 'C', '2', '5', '6',
				    'M', '1', '6', 'E', 'R', '-', 'E', 'K' },
};

const struct nonspd_mem_info samsung_k4b4g1646d = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		=
		{ 'K', '4', 'B', '4', 'G', '1', '6', '4', '6', 'D',
		  '-', 'B', 'Y', 'K', '0' },
};

const struct nonspd_mem_info samsung_k4b4g1646e = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		=
		{ 'K', '4', 'B', '4', 'G', '1', '6', '4', '6', 'E',
		  '-', 'B', 'Y', 'K', '0' },
};

const struct nonspd_mem_info samsung_k4b4g1646e_byma = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800, DDR_933 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		=
		{ 'K', '4', 'B', '4', 'G', '1', '6', '4', '6', 'E',
		  '-', 'B', 'Y', 'M', 'A' },
};

const struct nonspd_mem_info samsung_ddr3l_k4b4g1646d_byk0 = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		=
		{ 'K', '4', 'B', '4', 'G', '1', '6', '4', '6', 'D', '-',
		  'B', 'Y', 'K', '0' },
};

const struct nonspd_mem_info samsung_ddr3l_k4b4g1646q_hyk0 = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		=
		{ 'K', '4', 'B', '4', 'G', '1', '6', '4', '6', 'Q', '-',
		  'H', 'Y', 'K', '0' },
};

const struct nonspd_mem_info samsung_ddr3l_k4b8g1646q_myk0 = {
	.dram_type              = SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,
	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 16,
	.ddr_freq 		= { DDR_333, DDR_400, DDR_533, DDR_667, DDR_800 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		=
		{ 'K', '4', 'B', '8', 'G', '1', '6', '4', '6', 'Q', '-',
		  'M', 'Y', 'K', '0' },
};

const struct nonspd_mem_info samsung_lpddr3_k3qf2f20em_agce = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR3,
        .module_type.ddr3_type  = DDR3_MODULE_TYPE_SO_DIMM,

        .module_size_mbits      = 8192,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_400, DDR_533, DDR_667, DDR_800 },

        .module_mfg_id          = MFGID_SAMSUNG,
        .dram_mfg_id            = MFGID_SAMSUNG,

        .part_num               =
                { 'K', '3', 'Q', 'F', '2', 'F', '2', '0', 'E', 'M', '-',
                  'A', 'G', 'C', 'E' },
};

const struct nonspd_mem_info samsung_lpddr3_k4e6e304eb_egce = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800, DDR_933},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'E', '6', 'E', '3', '0', '4', 'E', 'B', '-',
		  'E', 'G', 'C', 'E' },
};

const struct nonspd_mem_info samsung_lpddr3_k4e6e304ee_egce = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800, DDR_933},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'E', '6', 'E', '3', '0', '4', 'E', 'E', '-',
		  'E', 'G', 'C', 'E' },
};

const struct nonspd_mem_info samsung_lpddr3_k4e6e304eb_egcf = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800, DDR_933},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'E', '6', 'E', '3', '0', '4', 'E', 'B', '-',
		  'E', 'G', 'C', 'F' },
};

const struct nonspd_mem_info samsung_lpddr3_k4e8e304ed_egcc = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_533 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.serial_num 		= { 0, 0, 0, 0 },
	.part_num		=
		{ 'K', '4', 'E', '8', 'E', '3', '0', '4', 'E', 'D', '-',
		  'E', 'G', 'C', 'C' },
};

const struct nonspd_mem_info samsung_lpddr3_k4e8e304ee_egce = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800, DDR_933 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'E', '8', 'E', '3', '0', '4', 'E', 'E', '-',
		  'E', 'G', 'C', 'E' },
};

const struct nonspd_mem_info samsung_lpddr3_k4e8e324eb_egcf = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_400, DDR_533, DDR_667, DDR_800, DDR_933 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'E', '8', 'E', '3', '2', '4', 'E', 'B', '-',
		  'E', 'G', 'C', 'F' },
};

const struct nonspd_mem_info micron_lpddr3_mt52l256m32d1pf_107wtb = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
	        { 'M', 'T', '5', '2', 'L', '2', '5', '6', 'M', '3', '2', 'D',
		  '1', 'P', 'F', '-', '1', '0', '7', 'W', 'T', ':', 'B' },
};

const struct nonspd_mem_info micron_lpddr3_mt52l256m64d2pp_107wtb = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
	        { 'M', 'T', '5', '2', 'L', '2', '5', '6', 'M', '6', '4', 'D',
		  '2', 'P', 'P', '-', '1', '0', '7', 'W', 'T', ':', 'B' },
};

const struct nonspd_mem_info micron_lpddr3_mt52l512m32d2pf_107wtb = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
	        { 'M', 'T', '5', '2', 'L', '5', '1', '2', 'M', '3', '2', 'D',
		  '2', 'P', 'F', '-', '1', '0', '7', 'W', 'T', ':', 'B' },
};

const struct nonspd_mem_info micron_lpddr4_mt53b256m32d1np = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
		{ 'M', 'T', '5', '3', 'B', '2', '5', '6', 'M', '3', '2', 'D',
		  '1', 'N', 'P'},
};

const struct nonspd_mem_info micron_lpddr4_mt53b512m32d2np = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
		{ 'M', 'T', '5', '3', 'B', '5', '1', '2', 'M', '3', '2', 'D',
		  '2', 'N', 'P'},
};

const struct nonspd_mem_info micron_lpddr4_mt53e512m32d2np = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
		{ 'M', 'T', '5', '3', 'E', '5', '1', '2', 'M', '3', '2', 'D',
		  '2', 'N', 'P'},
};

const struct nonspd_mem_info micron_lpddr4x_mt53e1g32d4nq_046wte = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq		= { DDR_800, DDR_1200, DDR_1600 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
		{ 'M', 'T', '5', '3', 'E', '1', 'G', '3', '2', 'D', '4', 'N',
		  'Q', '-', '4', '6', 'W', 'T', ':', 'E'},
};

const struct nonspd_mem_info micron_lpddr4x_mt53e1g32d2np_046wta = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq		= { DDR_2133 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num	=
		{ 'M', 'T', '5', '3', 'E', '1', 'G', '3', '2', 'D', '2', 'N',
		  'P', '-', '4', '6', 'W', 'T', ':', 'A'},
};

const struct nonspd_mem_info micron_lpddr4x_mt53e1g32d2np_046wtb = {
	.dram_type              = SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits      = 32768,
	.num_ranks              = 2,
	.device_width           = 32,

	.module_mfg_id          = MFGID_MICRON,
	.dram_mfg_id            = MFGID_MICRON,

	.part_num               = "MT53E1G32D2NP-46WT:B",
};

const struct nonspd_mem_info foresee_lpddr4x_feprf6432_58a1930 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq		= { DDR_2133 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
		{ 'F', 'E', 'P', 'R', 'F', '6', '4', '3', '2', '-', '5', '8',
		  'A', '1', '9', '3', '0'},
};

const struct nonspd_mem_info micron_lpddr4x_mt53e2g32d4nq_046wta = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 65536,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq		= { DDR_2133 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
		{ 'M', 'T', '5', '3', 'E', '2', 'G', '3', '2', 'D', '4', 'N',
		  'Q', '-', '4', '6', 'W', 'T', ':', 'A'},
};

const struct nonspd_mem_info micron_lpddr4x_mt29vzzzad8dqksl = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq		= { DDR_800, DDR_1200, DDR_1600 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
		{ 'M', 'T', '2', '9', 'V', 'Z', 'Z', 'Z', 'A', 'D', '8', 'D',
		  'Q', 'K', 'S', 'L'},
};

const struct nonspd_mem_info micron_lpddr4x_mt29vzzzcd9gqkpr_046 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq		= { DDR_2133 },

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		=
		{ 'M', 'T', '2', '9', 'V', 'Z', 'Z', 'Z', 'C', 'D', '9', 'G',
		  'Q', 'K', 'P', 'R', '-', '0', '4', '6'},
};

const struct nonspd_mem_info micron_lpddr4x_mt29vzzzad9gqfsm_046 = {
	.dram_type              = SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits      = 32768,
	.num_ranks              = 2,
	.device_width           = 32,
	.ddr_freq               = { DDR_2133 },

	.module_mfg_id          = MFGID_MICRON,
	.dram_mfg_id            = MFGID_MICRON,

	.part_num               =
		{ 'M', 'T', '2', '9', 'V', 'Z', 'Z', 'Z', 'A', 'D', '9', 'G',
		  'Q', 'F', 'S', 'M', '-', '0', '4', '6'},
};

const struct nonspd_mem_info samsung_lpddr4_k3uh5h50mm_agcj = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_1355 },

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '3', 'U', 'H', '5', 'H', '5', '0', 'M', 'M', '-',
		  'A', 'G', 'C', 'J' },
};

const struct nonspd_mem_info samsung_lpddr4_k4f6e304hb_mgcj = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'F', '6', 'E', '3', '0', '4', 'H', 'B', '-',
		  'M', 'G', 'C', 'J' },
};

const struct nonspd_mem_info samsung_lpddr4_k4f6e3s4hm_mgcj = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 16384,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'F', '6', 'E', '3', 'S', '4', 'H', 'M', '-',
		  'M', 'G', 'C', 'J' },
};

const struct nonspd_mem_info samsung_lpddr4_k4f8e304hb_mgcj = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'F', '8', 'E', '3', '0', '4', 'H', 'B', '-',
		  'M', 'G', 'C', 'J' },
};

const struct nonspd_mem_info samsung_lpddr4x_kmdh6001da_b422 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', 'M', 'D', 'H', '6', '0', '0', '1', 'D', 'A', '-',
		  'B', '4', '2', '2' },
};

const struct nonspd_mem_info samsung_lpddr4x_kmdp6001da_b425 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', 'M', 'D', 'P', '6', '0', '0', '1', 'D', 'A', '-',
		  'B', '4', '2', '5' },
};

const struct nonspd_mem_info samsung_lpddr4x_kmdv6001da_b620 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', 'M', 'D', 'V', '6', '0', '0', '1', 'D', 'A', '-',
		  'B', '6', '2', '0' },
};

const struct nonspd_mem_info samsung_lpddr4x_k4ube3d4am_mgcj = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'U', 'B', 'E', '3', 'D', '4', 'A', 'M', '-',
		  'M', 'G', 'C', 'J' },
};

const struct nonspd_mem_info samsung_lpddr4x_k4ube3d4aa_mgcl = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'U', 'B', 'E', '3', 'D', '4', 'A', 'A', '-',
		  'M', 'G', 'C', 'L' },
};

const struct nonspd_mem_info samsung_lpddr4x_k4ube3d4ab_mgcl = {
	.dram_type              = SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits      = 32768,
	.num_ranks              = 2,
	.device_width           = 32,

	.module_mfg_id          = MFGID_SAMSUNG,
	.dram_mfg_id            = MFGID_SAMSUNG,

	.part_num               = "K4UBE3D4AB-MGCL",
};

const struct nonspd_mem_info samsung_lpddr4x_k4ube3d4aa_mgcr = {
        .dram_type              = SPD_DRAM_TYPE_LPDDR4X,

        .module_size_mbits      = 32768,
        .num_ranks              = 2,
        .device_width           = 32,
        .ddr_freq               = { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

        .module_mfg_id          = MFGID_SAMSUNG,
        .dram_mfg_id            = MFGID_SAMSUNG,

        .part_num               =
                { 'K', '4', 'U', 'B', 'E', '3', 'D', '4', 'A', 'A', '-',
                  'M', 'G', 'C', 'R' },
};

const struct nonspd_mem_info samsung_lpddr4_k4f6e304hb_mgch = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SAMSUNG,
	.dram_mfg_id		= MFGID_SAMSUNG,

	.part_num		=
		{ 'K', '4', 'F', '6', 'E', '3', '0', '4', 'H', 'B', '-',
		  'M', 'G', 'C', 'H' },
};

const struct nonspd_mem_info sandisk_lpddr4x_sdada4cr_128g = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,
	.ddr_freq 		= { DDR_667, DDR_800, DDR_933, DDR_1067, DDR_1200},

	.module_mfg_id		= MFGID_SANDISK,
	.dram_mfg_id		= MFGID_SANDISK,

	.part_num		=
		{ 'S', 'D', 'A', 'D', 'A', '4', 'C', 'R', '-', '1', '2',
		  '8', 'G' },
};
