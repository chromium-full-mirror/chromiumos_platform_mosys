/*
 * Copyright 2010, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * Redistribution of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * Redistribution in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of Sun Microsystems, Inc. or the names of
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * 
 * This software is provided "AS IS," without a warranty of any kind.
 * ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED.
 * SUN MICROSYSTEMS, INC. ("SUN") AND ITS LICENSORS SHALL NOT BE LIABLE
 * FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, MODIFYING
 * OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.  IN NO EVENT WILL
 * SUN OR ITS LICENSORS BE LIABLE FOR ANY LOST REVENUE, PROFIT OR DATA,
 * OR FOR DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL, INCIDENTAL OR
 * PUNITIVE DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF
 * LIABILITY, ARISING OUT OF THE USE OF OR INABILITY TO USE THIS SOFTWARE,
 * EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * string.c: string utilities
 */

#include <ctype.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include "mosys/alloc.h"
#include "mosys/log.h"

#include "lib/string.h"

/*
 * buf2str  -  represent an array of bytes as a hex string (no prefix)
 *
 * @inbuf:      input array[]
 * @length:     buffer length
 *
 * returns allocated pointer to outbuf
 * returns NULL on failure
 */
char *buf2str(uint8_t *inbuf, size_t length)
{
	size_t i;
	char *outbuf;
	char *outp;

	if (inbuf == NULL)
		return NULL;

	outbuf = mosys_malloc(2*length + 1);
	outp = outbuf;

	for (i = 0; i < length; i++) {
		/* sprintf includes the NUL terminator */
		sprintf(outp, "%02x", inbuf[i]);
		outp += 2;
	}

	outbuf[2*length] = '\0';
	return outbuf;
}

char *strlower(char *str)
{
	char *p;

	for (p = str; *p; p++)
		*p = tolower(*p);

	return str;
}

char *strupper(char *str)
{
	char *p;

	for (p = str; *p; p++)
		*p = toupper(*p);

	return str;
}

size_t strlcpy(char *dest, const char *src, size_t size) {
	size_t copied = 0;

	if (size == 0)
		return 0;

	for (size_t i = 0; i < size - 1; i++) {
		if (*src == '\0')
			break;

		*dest = *src;
		dest++;
		src++;
		copied++;
	}

	*dest = '\0';
	return copied;
}
