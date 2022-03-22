// SPDX-License-Identifier: BSD-3-Clause
/*
 * Copyright 2015, Google Inc.
 * All rights reserved.
 */

#include "lib/nonspd_modules.h"

const struct nonspd_mem_info elpida_lpddr3_edfa164a2ma_jd_f = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x80 },

	.part_num		= "EDFA164A2MA-JD-F",
};

const struct nonspd_mem_info hynix_ddr3l_h5tc4g63afr_pba = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H5TC4G63AFR-PBA",
};

const struct nonspd_mem_info hynix_ddr3l_h5tc4g63cfr_pba = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H5TC4G63CFR-PBA",
};

const struct nonspd_mem_info hynix_ddr3l_h5tc4g63efr_rda = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H5TC4G63EFR-RDA",
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnn8gtmlar_nud = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H9CCNNN8GTMLAR-NUD",
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbjtalar_nud = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H9CCNNNBJTALAR-NUD",
};

const struct nonspd_mem_info hynix_ddr3l_h5tc8g63amr_pba = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,
	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H5TC8G63AMR-PBA",
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbptblbr_nud = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H9CCNNNBPTBLBR-NUD",
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbltblar_nud = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H9CCNNNBLTBLAR-NUD",
};

const struct nonspd_mem_info hynix_lpddr3_h9ccnnnbktmlbr_ntd = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H9CCNNNBKTMLBR-NTD",
};

const struct nonspd_mem_info hynix_lpddr4x_h9hcnnncpmalhr_nee = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H9HCNNNCPMALHR-NEE",
};

const struct nonspd_mem_info hynix_lpddr4x_h9hcnnncpmmlxr_nee = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H9HCNNNCPMMLXR-NEE",
};

const struct nonspd_mem_info hynix_lpddr4x_h9hcnnnfammlxr_nee = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	=  65536,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xad, .lsb = 0x80 },
	.dram_mfg_id		= { .msb = 0xad, .lsb = 0x80 },

	.part_num		= "H9HCNNNFAMMLXR-NEE",
};

const struct nonspd_mem_info micron_mt41k256m16ha = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT41K256M16HA-125",
};

const struct nonspd_mem_info nanya_ddr3l_nt5cc256m16dp_di = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	/* CL = 11, CWL = 8, min = 1.25ns, max <1.5ns */
	.module_mfg_id		= { .msb = 0x0b, .lsb = 0x03 },
	.dram_mfg_id		= { .msb = 0x0b, .lsb = 0x03 },

	.part_num		= "NT5CC256M16DP-DI",
};

const struct nonspd_mem_info nanya_ddr3l_nt5cc256m16er_ek = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,
	.module_mfg_id		= { .msb = 0x0b, .lsb = 0x03 },
	.dram_mfg_id		= { .msb = 0x0b, .lsb = 0x03 },

	.part_num		= "NT5CC256M16ER-EK",
};

const struct nonspd_mem_info nanya_lpddr3_nt6cl512t32am_h0 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,
	.module_mfg_id		= { .msb = 0x0b, .lsb = 0x03 },
	.dram_mfg_id		= { .msb = 0x0b, .lsb = 0x03 },

	.part_num		= "NT6CL512T32AM-H0",
};

const struct nonspd_mem_info samsung_k4b4g1646d = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4B4G1646D-BYK0",
};

const struct nonspd_mem_info samsung_k4b4g1646e = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4B4G1646E-BYK0",
};

const struct nonspd_mem_info samsung_k4b4g1646e_byma = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_UNDEFINED,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4B4G1646E-BYMA",
};

const struct nonspd_mem_info samsung_ddr3l_k4b4g1646d_byk0 = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4B4G1646D-BYK0",
};

const struct nonspd_mem_info samsung_ddr3l_k4b4g1646q_hyk0 = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 4096,
	.num_ranks		= 1,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4B4G1646Q-HYK0",
};

const struct nonspd_mem_info samsung_ddr3l_k4b8g1646q_myk0 = {
	.dram_type		= SPD_DRAM_TYPE_DDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,
	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 16,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4B8G1646Q-MYK0",
};

const struct nonspd_mem_info samsung_lpddr3_k3qf2f20em_agce = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K3QF2F20EM-AGCE",
};

const struct nonspd_mem_info samsung_lpddr3_k4e6e304eb_egce = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4E6E304EB-EGCE",
};

const struct nonspd_mem_info samsung_lpddr3_k4e6e304ee_egce = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4E6E304EE-EGCE",
};

const struct nonspd_mem_info samsung_lpddr3_k4e6e304eb_egcf = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4E6E304EB-EGCF",
};

const struct nonspd_mem_info samsung_lpddr3_k4e6e304ec_egcg = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id	= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id	= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4E6E304EC-EGCG",
};

const struct nonspd_mem_info samsung_lpddr3_k4e8e304ee_egce = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4E8E304EE-EGCE",
};

const struct nonspd_mem_info samsung_lpddr3_k4e8e324eb_egcf = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4E8E324EB-EGCF",
};

const struct nonspd_mem_info samsung_lpddr3_k4e6e304ed_egcg = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4E6E304ED-EGCG",
};

const struct nonspd_mem_info micron_lpddr3_mt52l256m32d1pf_107wtb = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT52L256M32D1PF-107WT:B",
};

const struct nonspd_mem_info micron_lpddr3_mt52l256m32d1pf_10 = {
	.dram_type = SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type = DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits = 2048 * 8,
	.num_ranks = 1,
	.device_width = 64,

	.module_mfg_id = { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id = { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT52L256M32D1PF-10",
};

const struct nonspd_mem_info micron_lpddr3_mt52l256m64d2pp_107wtb = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 8192,
	.num_ranks		= 1,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT52L256M64D2PP-107WT:B",
};

const struct nonspd_mem_info micron_lpddr3_mt52l512m32d2pf_107wtb = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type	= DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits	= 16384,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT52L512M32D2PF-107WT:B",
};

const struct nonspd_mem_info micron_lpddr3_mt52l512m32d2pf_10 = {
	.dram_type = SPD_DRAM_TYPE_LPDDR3,
	.module_type.ddr3_type = DDR3_MODULE_TYPE_SO_DIMM,

	.module_size_mbits = 4096 * 8,
	.num_ranks = 2,
	.device_width = 64,

	.module_mfg_id = { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id = { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT52L512M32D2PF-10",
};

const struct nonspd_mem_info micron_lpddr4x_mt53e1g32d4nq_046wte = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT53E1G32D4NQ-46WT:E",
};

const struct nonspd_mem_info micron_lpddr4x_mt53e1g32d2np_046wta = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 1,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT53E1G32D2NP-46WT:A",
};

const struct nonspd_mem_info foresee_lpddr4x_flxc2004g_n1 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= MFGID_MICRON,
	.dram_mfg_id		= MFGID_MICRON,

	.part_num		= "FLXC2004G-N1",
};

const struct nonspd_mem_info micron_lpddr4x_mt53e2g32d4nq_046wta = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 65536,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT53E2G32D4NQ-46WT:A",
};

const struct nonspd_mem_info micron_lpddr4x_mt53d1g32d4dt_046wtd = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT53D1G32D4DT-46WT:D",
};

const struct nonspd_mem_info micron_lpddr4x_mt29vzzzad8dqksl = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT29VZZZAD8DQKSL",
};

const struct nonspd_mem_info micron_lpddr4x_mt29vzzzad8gqfsl_046 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT29VZZZAD8GQFSL-046",
};

const struct nonspd_mem_info micron_lpddr4x_mt29vzzzbd9dqkpr_046 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT29VZZZBD9DQKPR-046",
};

const struct nonspd_mem_info micron_lpddr4x_mt29vzzzad9gqfsm_046 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT29VZZZAD9GQFSM-046",
};

const struct nonspd_mem_info micron_lpddr4x_mt29vzzzcd9gqkpr_046 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x2c, .lsb = 0x00 },

	.part_num		= "MT29VZZZCD9GQKPR-046",
};

const struct nonspd_mem_info samsung_lpddr4_k3uh5h50mm_agcj = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K3UH5H50MM-AGCJ",
};

const struct nonspd_mem_info samsung_lpddr4x_kmdh6001da_b422 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "KMDH6001DA-B422",
};

const struct nonspd_mem_info samsung_lpddr4x_kmdp6001da_b425 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "KMDP6001DA-B425",
};

const struct nonspd_mem_info samsung_lpddr4x_kmdv6001da_b620 = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "KMDV6001DA-B620",
};

const struct nonspd_mem_info samsung_lpddr4x_k4ube3d4aa_mgcl = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4UBE3D4AA-MGCL",
};

const struct nonspd_mem_info samsung_lpddr4x_k4ube3d4aa_mgcr = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4UBE3D4AA-MGCR",
};

const struct nonspd_mem_info samsung_lpddr4x_k4uce3q4aa_mgcr = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 65536,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0xce, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0xce, .lsb = 0x00 },

	.part_num		= "K4UCE3Q4AA-MGCR",
};

const struct nonspd_mem_info sandisk_lpddr4x_sdada4cr_128g = {
	.dram_type		= SPD_DRAM_TYPE_LPDDR4X,

	.module_size_mbits	= 32768,
	.num_ranks		= 2,
	.device_width		= 32,

	.module_mfg_id		= { .msb = 0x45, .lsb = 0x00 },
	.dram_mfg_id		= { .msb = 0x45, .lsb = 0x00 },

	.part_num		= "SDADA4CR-128G",
};
