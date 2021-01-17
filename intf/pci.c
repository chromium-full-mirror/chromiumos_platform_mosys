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
 * pci.c: Quick PCI access, requires linux /proc/bus/pci or
 * directory that has same structure
 *
 * FIXME: does not handle extended configuration space (>256B)
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <inttypes.h>
#include <dirent.h>

#include "mosys/platform.h"
#include "mosys/globals.h"
#include "mosys/log.h"

#include "lib/string.h"

#include "intf/pci.h"

/* default PCI root directory */
#define PCI_PROC_DIR	"/proc/bus/pci"

/*
 * pci_open_file  -  Open PCI dev file based on bus/dev/func under given root
 *
 * @bus:	pci bus number
 * @dev:	pci device id
 * @func:	pci function id
 * @rw:         read=0, write=1
 *
 * returns valid file descriptor on success
 * returns <0 on failure
 */
static int pci_open_file(int bus, int dev, int func, int rw)
{
	char pcif[1024];

	snprintf(pcif, sizeof(pcif), "%s/%02x/%02x.%x",
	         PCI_PROC_DIR, bus, dev, func);

	return open(pcif, rw);
}

/*
 * pci_read_file  -  Read from pci configuration space
 *
 * @intf:       platform interface
 * @bus:        pci bus
 * @dev:        pci device
 * @func:       pci function
 * @reg:        configuration register
 * @length:     number of bytes to read
 * @data:       buffer to read data into
 *
 * returns number of bytes read
 * returns <0 to indicate failure
 */
static int pci_read_file(struct platform_intf *intf, int bus,
                         int dev, int func, int reg, int length, void *data)
{
	int fd, rlen;

	lprintf(LOG_DEBUG,
	        "pci_read_file: reading %02x:%02x.%x at %02x (%d bytes)\n", bus,
	        dev, func, reg, length);

	if (length < 1 || length > 255)
		return -1;

	fd = pci_open_file(bus, dev, func, O_RDONLY);
	if (fd < 0) {
		lprintf(LOG_DEBUG,
		        "Unable to open PCI %02x:%02x.%1x for reading\n", bus,
		        dev, func);
		return -1;
	}

	/* seek to starting register */
	if (lseek(fd, reg, SEEK_SET) == (off_t) - 1) {
		lperror(LOG_DEBUG,
		        "Unable to read from PCI %02x:%02x.%1x at 0x%x", bus,
		        dev, func, reg);
		close(fd);
		return -1;
	}

	/* read the data */
	rlen = read(fd, data, length);

	if (rlen != length)
		lperror(LOG_DEBUG, "Unable to read %d bytes from PCI"
		        " %02x:%02x.%1x at 0x%x", length, bus, dev, func, reg);

	close(fd);

	return rlen;
}

/* PCI operations based on /proc directory */
struct pci_intf pci_file_intf = {
	.read		= pci_read_file,
};
