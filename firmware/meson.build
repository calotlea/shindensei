## SPDX-License-Identifier: CERN-OHL-W-2.0+
# @author Lea Calot
project('Shindensei',
	'c',
	version         : '0.1',
	license         : 'CERN-OHL-W-2.0 license',
	default_options : [
		'buildtype=minsize', 
		'c_std=c99',
	],
)

assert(meson.is_cross_build(), 'Use cross-build for Shindensei Target')
objcopy = find_program('riscv-none-embed-objcopy', required : true)
objdump = find_program('riscv-none-embed-objdump', required : true)

incdir = [
    include_directories('UART'),
    include_directories('Debug'),
    include_directories('USB_Device'),
    include_directories('core'),
    include_directories('peripheral/inc'),
]

t_executable = '@0@.elf'
t_bin = '@0@.bin'
t_hex = '@0@.hex'
t_asm = '@0@.S'
t_startup = 'Startup/startup_@0@.S'
t_flash = 'flash_@0@'

t_mapfile = '-Wl,-Map,@0@.map'
t_ldflag = '-Wl,-T'+meson.source_root()+'/'+'@0@.ld'

progs = [
	['hello',
	    ['UART/UART.c',
	     'USB_Device/ch32v20x_usbfs_device.c',
	     'USB_Device/usb_desc.c',
	     'Debug/debug.c',
	     'ch32v20x_it.c',
	     'main.c',
	     'system_ch32v20x.c',

	     'core/core_riscv.c',

	     'peripheral/src/ch32v20x_dma.c',
	     'peripheral/src/ch32v20x_gpio.c',
	     'peripheral/src/ch32v20x_usart.c',
	     'peripheral/src/ch32v20x_iwdg.c',
	     'peripheral/src/ch32v20x_tim.c',
	     'peripheral/src/ch32v20x_pwr.c',
	     'peripheral/src/ch32v20x_rcc.c',
	     'peripheral/src/ch32v20x_misc.c',
	     ],
    'Hello World Example',
    'ch32v20x_D8W'],
]

foreach p : progs

	exe = executable(t_executable.format(p[0]), [p[1], t_startup.format(p[3])],
		link_args : [t_mapfile.format(p[0]),
		    t_ldflag.format(p[3])],
		include_directories : [incdir],
		build_by_default : true,
	)
	bin = custom_target(t_bin.format(p[0]),
		output : [t_bin.format(p[0])],
		build_by_default : true,
		command : [objcopy, '-O', 'binary', t_executable.format(p[0]), t_bin.format(p[0])],
        depends : exe)
	hex = custom_target(t_hex.format(p[0]),
		output : [t_hex.format(p[0]),],
        build_by_default : true,
        command : [objcopy, '-O', 'ihex', t_executable.format(p[0]), t_hex.format(p[0])],
        depends : exe)
	asm = custom_target(t_asm.format(p[0]),
		output : t_asm.format(p[0]),
        build_by_default : true,
        command : [objdump, '-d', '-S', t_executable.format(p[0])],
		capture : true,
        depends : exe)
endforeach
