/* Copyright 2014, Google Inc.
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
 * nonspd.c: Functions for pretty printing memory info for systems without SPD.
 */

#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <valstr.h>

#include "jedec_id.h"
#include "lib/math.h"
#include "lib/nonspd.h"
#include "lib/string.h"
#include "lib/string_builder.h"
#include "mosys/platform.h"
#include "mosys/kv_pair.h"
#include "mosys/log.h"

/*
 * nonspd_print_field  -  add common DDR SPD fields into key=value pair
 *
 * @kv:         key=value pair
 * @info:       nonspd memory info
 * @type:       type of field to retrieve
 *
 * returns 1 to indicate data added to key=value pair
 * returns 0 to indicate no data added
 * returns <0 to indicate error
 *
 */
int nonspd_print_field(struct kv_pair *kv,
			const struct nonspd_mem_info *info,
			enum spd_field_type type)
{
	int ret = 0;

	switch (type) {
	case SPD_GET_DRAM_TYPE:
		switch (info->dram_type) {
		case SPD_DRAM_TYPE_DDR:
			kv_pair_add(kv, "dram", "DDR3");
			break;
		case SPD_DRAM_TYPE_DDR2:
			kv_pair_add(kv, "dram", "DDR2");
			break;
		case SPD_DRAM_TYPE_FBDIMM:
			kv_pair_add(kv, "dram", "FBDIMM");
			break;
		case SPD_DRAM_TYPE_DDR3:
			kv_pair_add(kv, "dram", "DDR3");
			break;
		case SPD_DRAM_TYPE_DDR4:
			kv_pair_add(kv, "dram", "DDR4");
			break;
		case SPD_DRAM_TYPE_JEDEC_LPDDR3:
		case SPD_DRAM_TYPE_LPDDR3:
			kv_pair_add(kv, "dram", "LPDDR3");
			break;
		case SPD_DRAM_TYPE_LPDDR4:
			kv_pair_add(kv, "dram", "LPDDR4");
			break;
		case SPD_DRAM_TYPE_LPDDR4X:
			kv_pair_add(kv, "dram", "LPDDR4X");
			break;
		default:
			break;
		}
		ret = 1;
		break;

	case SPD_GET_MODULE_TYPE:
		switch (info->dram_type) {
		case SPD_DRAM_TYPE_DDR3:
		case SPD_DRAM_TYPE_LPDDR3:
		case SPD_DRAM_TYPE_JEDEC_LPDDR3:
			kv_pair_add(kv, "module",
			            val2str(info->module_type.ddr3_type,
					    ddr3_module_type_lut));
			ret = 1;
			break;
		case SPD_DRAM_TYPE_DDR:
		case SPD_DRAM_TYPE_DDR2:
		case SPD_DRAM_TYPE_DDR4:
		case SPD_DRAM_TYPE_FBDIMM:
		default:
			ret = -1;
			break;
		}
		break;

	case SPD_GET_MFG_ID:
	{
		uint8_t manuf_lsb = info->module_mfg_id.lsb & 0x7f;
		uint8_t manuf_msb = info->module_mfg_id.msb & 0x7f;
		const char *tstr;

		tstr = jedec_manufacturer(manuf_lsb, manuf_msb);

		if (tstr != NULL) {
			kv_pair_fmt(kv, "module_mfg", "%u-%u: %s", manuf_lsb + 1,
			            manuf_msb, tstr);
		} else {
			kv_pair_fmt(kv, "module_mfg", "%u-%u", manuf_lsb + 1,
			            manuf_msb);
		}
		ret = 1;
		break;
	}

	case SPD_GET_MFG_ID_DRAM:
	{
		uint8_t manuf_lsb = info->dram_mfg_id.lsb & 0x7f;
		uint8_t manuf_msb = info->dram_mfg_id.msb & 0x7f;
		const char *tstr;

		tstr = jedec_manufacturer(manuf_lsb, manuf_msb);

		if (tstr != NULL) {
			kv_pair_fmt(kv, "dram_mfg", "%u-%u: %s",
			            manuf_lsb + 1, manuf_msb, tstr);
		} else {
			kv_pair_fmt(kv, "dram_mfg", "%u-%u",
			            manuf_lsb + 1, manuf_msb);
		}
		ret = 1;
		break;
	}

	case SPD_GET_MFG_LOC:
	{
		kv_pair_fmt(kv, "mfg_loc", "0x%02x", info->mfg_loc);
		ret = 1;
		break;
	}

	case SPD_GET_MFG_DATE: /* manufacturing date (BCD values) */
	{
		uint8_t year = info->module_mfg_date.year;
		uint8_t week = info->module_mfg_date.week;

		kv_pair_fmt(kv, "mfg_date", "20%02x-wk%02x", week, year);
		ret = 1;
		break;
	}

	case SPD_GET_SERIAL_NUMBER:
	{
		kv_pair_fmt(kv, "serial_number", "%02x%02x%02x%02x",
		            info->serial_num[0], info->serial_num[1],
		            info->serial_num[2], info->serial_num[3]);
		ret = 1;
		break;
	}

	case SPD_GET_PART_NUMBER:
	{
		char part[sizeof(info->part_num)+1];

		memcpy(part, &info->part_num[0], sizeof(info->part_num));
		part[sizeof(info->part_num)] = '\0';
		kv_pair_fmt(kv, "part_number", "%s", part);

		ret = 1;
		break;
	}

	case SPD_GET_REVISION_CODE:
	{
		kv_pair_fmt(kv, "revision_code", "0x%02x%02x",
		            info->revision[0],
			    info->revision[1]);
		ret = 1;
		break;
	}

	case SPD_GET_SIZE:
	{
		/* translate mbits to mbytes */
		kv_pair_fmt(kv, "size_mb", "%u", info->module_size_mbits / 8);
		ret = 1;
		break;
	}

	case SPD_GET_RANKS:
	{
		kv_pair_fmt(kv, "ranks", "%d", info->num_ranks);
		ret = 1;
		break;
	}

	case SPD_GET_WIDTH:
	{
		kv_pair_fmt(kv, "width", "%d", info->device_width);
		ret = 1;
		break;
	}

	case SPD_GET_SPEEDS:
	{
		int i, first_entry = 1;
		struct string_builder *speeds = new_string_builder();

		for (i = 0; i < ARRAY_SIZE(info->ddr_freq); i++) {
			if (!info->ddr_freq[i])
				continue;

			if (!first_entry)
				string_builder_strcat(speeds, ", ");
			else
				first_entry = 0;

			switch (info->dram_type) {
			case SPD_DRAM_TYPE_DDR3:
				string_builder_strcat(speeds, "DDR3-");
				break;
			case SPD_DRAM_TYPE_DDR4:
				string_builder_strcat(speeds, "DDR4-");
				break;
			case SPD_DRAM_TYPE_LPDDR3:
			case SPD_DRAM_TYPE_JEDEC_LPDDR3:
				string_builder_strcat(speeds, "LPDDR3-");
				break;
			case SPD_DRAM_TYPE_LPDDR4:
				string_builder_strcat(speeds, "LPDDR4-");
				break;
			case SPD_DRAM_TYPE_LPDDR4X:
				string_builder_strcat(speeds, "LPDDR4X-");
				break;
			default:
				break;
			}

			string_builder_strcat(speeds,
				ddr_freq_prettyprint[info->ddr_freq[i]]);
		}

		kv_pair_add(kv, "speeds", string_builder_get_string(speeds));
		free_string_builder(speeds);
		ret = 1;
		break;
	}

	default:
		break;
	}

	return ret;
}

// This one is reserved for storing mem info from SMBIOS if no explicit entry
// was added above.
static struct nonspd_mem_info part_extracted_from_smbios = {
	.part_num		=
		{ 'U', 'N', 'P', 'R', 'O', 'V', 'I', 'S', 'I', 'O', 'N', 'E', 'D'},
};

static const struct nonspd_mem_info *nospdmemory[] = {
	&elpida_lpddr3_edfa164a2ma_jd_f,
	&elpida_lpddr3_f8132a3ma_gd_f,
	&elpida_lpddr3_fa232a2ma_gc_f,
	&hynix_ddr3l_h5tc4g63afr_pba,
	&hynix_ddr3l_h5tc4g63cfr_pba,
	&hynix_ddr3l_h5tc4g63efr_rda,
	&hynix_lpddr3_h9ccnnn8gtmlar_nud,
	&hynix_lpddr3_h9ccnnnbjtalar_nud,
	&hynix_lpddr3_h9ccnnnbjtmlar_nud,
	&hynix_ddr3l_h5tc8g63amr_pba,
	&hynix_lpddr3_h9ccnnnbptblbr_nud,
	&hynix_lpddr3_h9ccnnnbltblar_nud,
	&hynix_lpddr3_h9ccnnnbktmlbr_ntd,
	&hynix_lpddr4_h9hcnnn8kumlhr,
	&hynix_lpddr4_h9hcnnnbpumlhr,
	&hynix_lpddr4x_h9hcnnncpmalhr_nee,
	&hynix_lpddr4x_h9hcnnncpmmlxr_nee,
	&micron_lpddr3_mt52l256m32d1pf_107wtb,
	&micron_lpddr3_mt52l256m64d2pp_107wtb,
	&micron_lpddr3_mt52l512m32d2pf_107wtb,
	&micron_lpddr4_mt53b256m32d1np,
	&micron_lpddr4_mt53b512m32d2np,
	&micron_lpddr4_mt53e512m32d2np,
	&micron_lpddr4x_mt29vzzzad8dqksl,
	&micron_lpddr4x_mt53e1g32d4nq_046wte,
	&micron_lpddr4x_mt53e1g32d2np_046wta,
	&micron_lpddr4x_mt53e2g32d4nq_046wta,
	&micron_mt41k256m16ha,
	&micron_mt52l256m32d1pf,
	&micron_mt52l512m32d2pf,
	&nanya_ddr3l_nt5cc256m16dp_di,
	&nanya_ddr3l_nt5cc256m16er_ek,
	&samsung_k4b4g1646d,
	&samsung_k4b4g1646e,
	&samsung_k4b4g1646e_byma,
	&samsung_ddr3l_k4b4g1646d_byk0,
	&samsung_ddr3l_k4b4g1646q_hyk0,
	&samsung_ddr3l_k4b8g1646q_myk0,
	&samsung_lpddr3_k3qf2f20em_agce,
	&samsung_lpddr3_k4e6e304eb_egce,
	&samsung_lpddr3_k4e6e304ee_egce,
	&samsung_lpddr3_k4e6e304eb_egcf,
	&samsung_lpddr3_k4e8e304ed_egcc,
	&samsung_lpddr3_k4e8e304ee_egce,
	&samsung_lpddr3_k4e8e324eb_egcf,
	&samsung_lpddr4_k3uh5h50mm_agcj,
	&samsung_lpddr4_k4f6e304hb_mgch,
	&samsung_lpddr4_k4f6e304hb_mgcj,
	&samsung_lpddr4_k4f6e3s4hm_mgcj,
	&samsung_lpddr4_k4f8e304hb_mgcj,
	&samsung_lpddr4x_kmdh6001da_b422,
	&samsung_lpddr4x_kmdp6001da_b425,
	&samsung_lpddr4x_kmdv6001da_b620,
	&samsung_lpddr4x_k4ube3d4am_mgcj,
	&samsung_lpddr4x_k4ube3d4aa_mgcl,
	&sandisk_lpddr4x_sdada4cr_128g
};

static int transfer_speed_from_smbios_to_nonspd_mem_info(
	struct smbios_table *table,
	struct nonspd_mem_info *info)
{
	for (int index = DDR_333; index < DDR_FREQ_MAX; index++) {
		if (table->data.mem_device.speed == atoi(ddr_freq_prettyprint[index])) {
			info->ddr_freq[0] = index;
			return 0;
		}
	}

	lprintf(LOG_ERR, "%s: mem speed %hu in SMBIOS is out of range.",
			__func__, table->data.mem_device.speed);
	return -1;
}

enum spd_dram_type map_smbios_mem_type_to_spd(struct smbios_table *table)
{
	switch (table->data.mem_device.type) {
	case SMBIOS_MEMORY_TYPE_DDR:
		return SPD_DRAM_TYPE_DDR;
	case SMBIOS_MEMORY_TYPE_DDR2:
		return SPD_DRAM_TYPE_DDR2;
	case SMBIOS_MEMORY_TYPE_DDR2_FBDIMM:
		return SPD_DRAM_TYPE_FBDIMM;
	case SMBIOS_MEMORY_TYPE_DDR3:
		return SPD_DRAM_TYPE_DDR3;
	case SMBIOS_MEMORY_TYPE_DDR4:
		return SPD_DRAM_TYPE_DDR4;
	case SMBIOS_MEMORY_TYPE_LPDDR3:
		return SPD_DRAM_TYPE_LPDDR3;
	case SMBIOS_MEMORY_TYPE_LPDDR4:
		return SPD_DRAM_TYPE_LPDDR4;
	default:
		lprintf(LOG_ERR, "%s: Unknown SMBIOS memory type: %d\n",
			__func__, table->data.mem_device.type);
		return 0;
	}
}

static int extract_mem_info_from_smbios(
	struct smbios_table *table,
	struct nonspd_mem_info *info)
{
	const char *smbios_part_num;
	size_t smbios_part_num_len, max_part_num_len;
	uint32_t size;

	max_part_num_len = sizeof(info->part_num) - 1;
	smbios_part_num = table->string[table->data.mem_device.part_number];
	smbios_part_num_len = strlen(smbios_part_num);

	if (!smbios_part_num_len ||
		smbios_part_num_len > max_part_num_len) {
		lprintf(LOG_ERR, "%s: SMBIOS Memory info table: part num is missing. "
				"Or len of part number %lu is larger then buffer %lu."
				, __func__, (unsigned long)smbios_part_num_len,
				(unsigned long)max_part_num_len);
		return -1;
	}

	size = (table->data.mem_device.size & 0x7fff) * 8;
	info->module_size_mbits =
		(table->data.mem_device.size & 0x8000 ? size * 1024 : size);

	strncpy((char *)info->part_num, smbios_part_num, max_part_num_len);

	info->dram_type = map_smbios_mem_type_to_spd(table);
	info->num_ranks = table->data.mem_device.attributes & 0xf;
	info->device_width = table->data.mem_device.data_width;

	return transfer_speed_from_smbios_to_nonspd_mem_info(table, info);
}

int spd_set_nonspd_info(struct platform_intf *intf,
                        const struct nonspd_mem_info **info)
{
	int dimm = 0, index;
	struct smbios_table table;

	if (smbios_find_table(intf, SMBIOS_TYPE_MEMORY, dimm, &table,
			SMBIOS_LEGACY_ENTRY_BASE,
			SMBIOS_LEGACY_ENTRY_LEN) < 0) {
		lprintf(LOG_ERR, "%s: SMBIOS Memory info table missing\n"
			, __func__);
		return -1;
	}

	for (index = 0; index < ARRAY_SIZE(nospdmemory); index++) {
		if (!strncmp(table.string[table.data.mem_device.part_number],
			(const char *)nospdmemory[index]->part_num,
			sizeof(nospdmemory[index]->part_num))) {
			*info = nospdmemory[index];
			break;
		}
	}

	if (index < ARRAY_SIZE(nospdmemory)) {
		return 0;
	}

	// memory device from SMBIOS is mapped into a nonspd_mem_info.
	if (extract_mem_info_from_smbios(&table, &part_extracted_from_smbios)) {
		return -1;
	}

	*info = &part_extracted_from_smbios;

	return 0;
}
