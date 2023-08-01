/*
 * Copyright 2012 Google LLC
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
 *    * Neither the name of Google LLC nor the names of its
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

#ifndef MOSYS_PLATFORM_H__
#define MOSYS_PLATFORM_H__

#include <stdbool.h>
#include <sys/types.h>
#include <stdint.h>

struct kv_pair;
struct nonspd_mem_info;

/* defined platform types */
enum platform_type {
	PLATFORM_DEFAULT,
	PLATFORM_X86_64,
	PLATFORM_ARMV7,
	PLATFORM_ARMV8,
};

/*
 *  Command types. These are exposed via "mosys -tv" to help with automated
 *  testing.
 */
enum arg_type {
	ARG_TYPE_GETTER, /* "getter" functions */
	ARG_TYPE_SETTER, /* "setter" functions */
	ARG_TYPE_SUB, /* branch deeper into command hierachy */
};

/* nested command lists */
struct platform_intf;
struct platform_cmd {
	const char *name; /* command name */
	const char *desc; /* command help text */
	const char *usage; /* command usage text */
	enum arg_type type; /* argument type */

	union { /* sub-commands or function */
		struct platform_cmd *sub;
		int (*func)(struct platform_intf *intf,
			    struct platform_cmd *cmd, int argc, char **argv);
	} arg;
};

/* memory related callbacks */
struct smbios_table;

struct memory_cb {
	int (*dimm_count)(struct platform_intf *intf);
	int (*nonspd_mem_info)(struct platform_intf *intf, int dimm,
			       const struct nonspd_mem_info **info);
};

/* platform-specific callbacks */
struct platform_cb {
	struct memory_cb *memory; /* memory callbacks */
};

/*
 * Top-level interface handler.
 * One of these should be defined for each supported platform.
 */
struct platform_intf {
	enum platform_type type; /* numeric platform type */
	const char *name; /* canonical platform name */
	struct platform_cmd **sub; /* list of commands */
	struct platform_cb *cb; /* callbacks */

	int (*setup)(struct platform_intf *intf);
};

/* Used for the global linked-list of all platforms. */
struct platform_list {
	struct platform_intf *entry;
	struct platform_list *next;
};

/**
 * REGISTER_PLATFORM - Macro to register a platform_intf in the global
 * platforms list.
 *
 * @intf:       The platform interface to register.
 * @name:       The name of the platform.  For unibuild devices, this
 *              platform_intf will be matched based on a comparison to
 *              /identity:platform-name in cros_config.
 *
 * This should be placed after the definition of a platform_intf, like so:
 *    static struct platform_intf platform_foo {
 *         ...
 *    };
 *    REGISTER_PLATFORM(platform_foo, "Foo");
 */
#define REGISTER_PLATFORM(intf, name) \
	_REGISTER_PLATFORM(intf, name, _register_platform_##intf)

/*
 * _REGISTER_PLATFORM Internal helper macro for REGISTER_PLATFORM.
 *
 * @_intf:        Platform interface.
 * @_name:        The name of the platform.
 * @function_id:  Identifier to be used for the generated function.
 *
 * This works by creating a constructor function [1] which
 * conditionally places the platform interface into the global list
 * before main runs.  In the case that _PLATFORM_IS_ENABLED(_name) can
 * be determined to be false at compile-time, the entire function,
 * including the references to the platform interface, will be
 * optimized away by the compiler.
 *
 * [1]: https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html
 */
#define _REGISTER_PLATFORM(_intf, _name, function_id)                       \
	static void __attribute__((constructor)) function_id(void)          \
	{                                                                   \
		_Static_assert(                                             \
			__builtin_constant_p(_name),                        \
			"Platform names must be a compile-time constant."); \
		if (!__builtin_strcmp(CONFIG_SINGLE_PLATFORM, _name)) {     \
			platform_intf = &(_intf);                           \
			platform_intf->name = _name;                        \
		}                                                           \
	}

/**
 * platform_intf - The registered platform.
 *
 * Used internally by REGISTER_PLATFORM, as well as platform.c.
 */
extern struct platform_intf *platform_intf;

/*
 * mosys_platform_setup  -  determine current platform and return handler
 *
 * returns pointer to pre-defined interface for detected platform
 * returns NULL if platform not identified or other error
 *
 */
extern struct platform_intf *mosys_platform_setup(void);

/*
 * platform_cmd_usage  -  print usage help text for command
 *
 * @cmd:	command pointer
 *
 */
extern void platform_cmd_usage(struct platform_cmd *cmd);

/*
 * print_tree - print command tree for this platform
 *
 * @intf:	platform interface
 */
extern void print_tree(struct platform_intf *intf);

#endif /* MOSYS_PLATFORM_H__ */
