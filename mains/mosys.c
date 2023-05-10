/* Copyright 2020 The ChromiumOS Authors
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <errno.h>
#include <fcntl.h>
#include <linux/securebits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef CONFIG_UNIBUILD
#include <sys/capability.h>
#include <chromeos/libminijail.h>
#endif

#include "mosys/cli.h"

#ifndef CONFIG_UNIBUILD
#define MOSYS_CAPS CAP_TO_MASK(CAP_SYS_RAWIO) | CAP_TO_MASK(CAP_SYS_ADMIN)
#define MOSYS_SECCOMP_POLICY_PATH "/usr/share/policy/mosys-seccomp.policy"

static void setup_jail(void)
{
	int fd;
	struct minijail *j;

	/* Don't setup the minijail if we aren't running as root. */
	if (geteuid() > 0)
		return;

	j = minijail_new();

	minijail_use_caps(j, MOSYS_CAPS);
	minijail_set_ambient_caps(j);

	/* Don't set securebits because this may be inside another minijail.
	   See b/112030238. */
	minijail_skip_setting_securebits(j, SECURE_ALL_BITS | SECURE_ALL_LOCKS);
	minijail_remount_proc_readonly(j);
	minijail_namespace_net(j);

	minijail_no_new_privs(j);
	minijail_set_seccomp_filter_tsync(j);

	/* This file is expected to not be present in initramfs.  Only
	   set the seccomp policy when it exists. */
	fd = open(MOSYS_SECCOMP_POLICY_PATH, O_RDONLY);
	if (fd >= 0) {
		minijail_parse_seccomp_filters_from_fd(j, fd);
		minijail_use_seccomp_filter(j);
		close(fd);
	}

	minijail_enter(j);
	minijail_destroy(j);
}
#endif

int main(int argc, char *argv[])
{
#ifndef CONFIG_UNIBUILD
	setup_jail();
#endif
	return mosys_main(argc, argv);
}
