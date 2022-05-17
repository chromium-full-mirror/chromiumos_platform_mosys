/*
 * Copyright 2013 Google Inc.
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
 * cros_ec_dev.c: Chrome EC interface via /dev
 */

#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <linux/limits.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "mosys/alloc.h"
#include "mosys/globals.h"
#include "mosys/log.h"
#include "mosys/platform.h"

#include "drivers/google/cros_ec.h"
#include "drivers/google/cros_ec_dev.h"
#include "drivers/google/cros_ec_commands.h"

#include "lib/file.h"
#include "lib/math.h"

#define CROS_EC_COMMAND_RETRIES	50

/*
 * ec device interface v2
 * (used with upstream kernel as well as with Chrome OS v4.4 and later)
 */

static int command_wait_for_response_v2(struct cros_ec_priv *priv)
{
	uint8_t s_cmd_buf[sizeof(struct cros_ec_command_v2) +
			  sizeof(struct ec_response_get_comms_status)];
	struct ec_response_get_comms_status *status;
	struct cros_ec_command_v2 *s_cmd;
	int ret;
	int i;

	s_cmd = (struct cros_ec_command_v2 *)s_cmd_buf;
	status = (struct ec_response_get_comms_status *)s_cmd->data;

	s_cmd->version = 0;
	s_cmd->command = EC_CMD_GET_COMMS_STATUS;
	s_cmd->outsize = 0;
	s_cmd->insize = sizeof(*status);

	for (i = 1; i <= CROS_EC_COMMAND_RETRIES; i++) {
		ret = ioctl(priv->devfs->fd, CROS_EC_DEV_IOCXCMD_V2, s_cmd_buf,
			    sizeof(s_cmd_buf));
		if (ret) {
			lprintf(LOG_ERR, "%s: CrOS EC command failed: %d\n",
				 __func__, ret);
			ret = -EC_RES_ERROR;
			break;
		}

		if (!(status->flags & EC_COMMS_STATUS_PROCESSING)) {
			ret = -EC_RES_SUCCESS;
			break;
		}

		usleep(1000);
	}

	return ret;
}

static int cros_ec_command_dev_v2(struct ec_cb *ec, int command, int version,
				  const void *indata, int insize,
				  const void *outdata, int outsize)
{
	struct cros_ec_priv *priv;
	struct cros_ec_command_v2 *s_cmd;
	int size = sizeof(struct cros_ec_command_v2) + __max(outsize, insize);
	int ret;
	uint32_t result;

	MOSYS_DCHECK(ec && ec->priv);
	priv = ec->priv;

	s_cmd = mosys_malloc(size);
	s_cmd->command = command;
	s_cmd->version = version;
	s_cmd->result = 0xff;
	s_cmd->outsize = outsize;
	s_cmd->insize = insize;
	if (outdata)
		memcpy(s_cmd->data, outdata, outsize);

	ret = ioctl(priv->devfs->fd, CROS_EC_DEV_IOCXCMD_V2, s_cmd, size);
	if (ret < 0 && errno == EAGAIN)
		ret = command_wait_for_response_v2(priv);
	if (ret < 0) {
		lprintf(LOG_ERR, "%s: Transfer failed: %d\n", __func__, ret);
		free(s_cmd);
		return -EC_RES_ERROR;
	}

	/*
	 * The function parameter declares indata as pointer to a constant char,
	 * which does not make much sense as its content is expected to be
	 * overwritten by this function. Use a typecast for now to avoid the
	 * inevitable warning.
	 */
	if (indata)
		memcpy((void *)indata, s_cmd->data, __min(ret, insize));
	result = s_cmd->result;
	free(s_cmd);

	/* TODO: Remove this. Issue 695075. */
	if (command != EC_CMD_PD_CHIP_INFO)
		return 0;

	if (result) {
		lprintf(LOG_ERR, "%s: EC command failed: 0x%x\n",
			__func__, result);
		return -EECRESULT - result;
	}

	return 0;
}

/*
 * cros_ec_probe_dev - Probe for CrOS EC type device using devfs.
 *
 * @intf:	The platform interface
 * @ec:		EC interface, can be for any CrOS EC type (EC, PD, SH, etc)
 *
 * returns 1 if EC is detected
 * returns 0 if EC is not detected
 * returns <0 to indicate error
 */
int cros_ec_probe_dev(struct ec_cb *ec)
{
	struct cros_ec_priv *priv = ec->priv;

	MOSYS_CHECK(priv && priv->devfs && priv->devfs->name);
	priv->devfs->fd = open(priv->devfs->name, O_RDWR);

	if (priv->devfs->fd < 0) {
		lprintf(LOG_ERR, "%s: Unable to open %s: %s.", __func__,
			priv->devfs->name, strerror(errno));
		return -1;
	}

	priv->cmd = cros_ec_command_dev_v2;
	return 1;
}
