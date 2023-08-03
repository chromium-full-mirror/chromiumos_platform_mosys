project('mosys', 'c', default_options : ['platform_intf=generic'])

# Include common. This is passed to all subdir build files as well
include_common = include_directories(['include'])

# Config data used for creating a config header and including it
conf_data = configuration_data()

# Setting on a per-arch basis
arch = host_machine.cpu_family()
if arch == 'x86' or arch == 'x86_64'
  conf_data.set('CONFIG_PLATFORM_ARCH_X86', 1)
  platform_subdir = 'x86_64'
elif arch == 'arm' or arch == 'aarch64'
  conf_data.set('CONFIG_PLATFORM_ARCH_ARMEL', 1)
  platform_subdir = 'arm'
endif

platform_intf = get_option('platform_intf').to_lower()

# Create the config header file and include it by default while compiling
configure_file(
  output : 'config.h',
  configuration : conf_data,
)
add_global_arguments('-include', 'config.h', language: 'c')
add_global_arguments('-std=gnu99', language : 'c')

cc = meson.get_compiler('c')
add_global_arguments('-Wall', language : 'c')
add_global_arguments('-Werror', language : 'c')
add_global_arguments('-Wstrict-prototypes', language : 'c')
add_global_arguments('-Wundef', language : 'c')

# Require that externally-visible symbols have a prototype.  This
# helps find missing usages of 'static'.
add_global_arguments('-Wmissing-variable-declarations', language : 'c')
add_global_arguments('-Wmissing-prototypes', language : 'c')

libmosys_src = files()
platform_support_src = files()
unittest_src = files()

# Subdirs with source to link against
subdir('core')
subdir('lib')
subdir('platform')
subdir('mains')
subdir('unittests')
