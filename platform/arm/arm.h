/* Copyright 2024 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef PLATFORM_ARM_H
#define PLATFORM_ARM_H

#include "mosys/platform.h"

/* platform callbacks */
extern struct memory_cb arm_memory_cb;

/*
 * get_dram_part_num - Get DRAM_PART_NUM from CBI.
 *
 * @buf :      buffer for storing DRAM_PART_NUM
 * @buf_size : buffer size
 *
 * returns 0 to indicate success, otherwise failure.
 */
int get_dram_part_num(uint8_t *buf, size_t buf_size);

#endif /* PLATFORM_ARM_H */
