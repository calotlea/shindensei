# Shindensei Firmware Development

## Current Status

The firmware for Shindensei is in the preliminary stages of development, designed to be compatible with the [WCH CH32V208W development system](https://www.aliexpress.com/item/1005005618694083.html). It's important to note that the PCB design is still undergoing validation. At present, the firmware primarily serves as a basic USB functionality example, with advanced features from the NeoDK firmware yet to be integrated.

## Development Environment

The firmware is developed using the RISC-V toolchain included in [MounRiver Studio](http://www.mounriver.com/). For those preferring a standalone setup, the firmware can also be compiled using the [Meson Build System](https://mesonbuild.com/), a powerful and efficient build system.

## Building the Firmware

To compile the firmware, follow these steps:

1. **Toolchain Installation**:
    - Download and install [MounRiver Studio](http://www.mounriver.com/).
    - Ensure that `riscv-none-embed-gcc` is added to your system path.

2. **Meson Build System**:
    - Install the [Meson Build System](https://mesonbuild.com/Quick-guide.html) along with its required dependencies.

3. **Project Configuration**:
    - Configure the project for cross-compilation using Meson:
      ```bash
      meson <builddir> --cross-file cross.ini
      ```
    - Execute the above command in your terminal, replacing `<builddir>` with your build directory name.

For additional information or to return to the main documentation, visit the [Home Page](../README.md).
