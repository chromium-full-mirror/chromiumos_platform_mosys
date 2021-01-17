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
 * PCI (Peripheral Component Interconnect) Interface
 */

#ifndef MOSYS_INTF_PCI_H__
#define MOSYS_INTF_PCI_H__

#include <inttypes.h>

#include "mosys/platform.h"

struct platform_intf;

struct pci_intf {
	/*
	 * read  -  Read from PCI configuration space
	 *
	 * @intf:     platform interface
	 * @bus:      pci bus
	 * @dev:      pci device
	 * @func:     pci function
	 * @reg:      configuration register
	 * @length:   number of bytes to read
	 * @data:     buffer to read data into
	 *
	 * returns number of bytes read
	 * returns <0 to indicate failure
	 */
	int (*read)(struct platform_intf *intf,
		    int bus, int dev, int func, int reg,
		    int length, void *data);
};

/* PCI operations based on /proc directory */
extern struct pci_intf pci_file_intf;

/*
 * The following are helpers to make call-sites easier
 */

/*
 * pci_read  -  read from PCI config space
 *
 * @intf:     platform interface
 * @bus:      PCI bus
 * @dev:      PCI device
 * @func:     PCI function
 * @reg:      configuration register
 * @length:   number of bytes to read
 * @data:     buffer to read data into
 *
 * returns <0 if failure, 0 on success
 */
static inline int
pci_read(struct platform_intf *intf, int bus, int dev, int func, int reg,
          size_t length, void *data)
{
	if (intf->op->pci->read(intf, bus, dev, func, reg, length, data)
	    != length) {
		return -1;
	}
	return 0;
}

/*
 * pci_read32  -  read 32 bits from PCI config space
 */
static inline int
pci_read32(struct platform_intf *intf, int bus, int dev, int func, int reg,
           uint32_t *data)
{
	return pci_read(intf, bus, dev, func, reg, sizeof(*data), data);
}

#endif /* MOSYS_INTF_PCI_H__ */
