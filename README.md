# Nucleo-144 STM32 F746 libopencm3 template 
This template is for vscode development with stlink debugger and it utilises the open source [libopencm3](https://github.com/libopencm3/libopencm3) library for the abstraction layer. It includes blinky code on LD2 of the nucleo board. It sets up the rcc clock settings that achieves 72MHz FCLK speed using the predefined pll configuration in libopencm3/stm32/rcc.c settings. It also provides basic vscode settings to get started with debugging. 

Credits to [low byte production](https://github.com/lowbyteproductions/bare-metal-series/tree/main). This github page and his youtube video series helped me setup this development environment. 

## Prerequisites
1. Go to the [libopencm3](https://github.com/libopencm3/libopencm3#prerequisites) and follow the prerequisites. For MacOs user, go to [Arm GNU Tool chains](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads). Download both the `eabi` and `elf` packages.
2. In VsCode, some useful extensions to install
    - Cortex-Debug
    - C/C++
    - C/C++ Extension Pack
    - GNU Linker Map files

## Setting up
1. Clone this repository.
2. Run the following command inside the repository to get the libopencm3 repository.
    ```bash
    $ git submodule init
    $ git submodule update
    ```
3. To build the libopencm3 library, go into the `libopencm3` directory and run 
    ```bash
    $ make
    ```
4. In the `.vscode` directory, open `c_cpp_properties.json`. Make sure that the `compilerPath` field is where your gnu toolchain lies (`bin` file).
5. To build the blinky application, go to the `app` directory and run
    ```bash
    $ make
    ```

## Flash and Debug
On the left side of your vscode window, click on the debug/play icon. Press the run button to flash your code.

Now you can press the other play button right next to the "firmware" tab.


# Working with another board/system
It is possible to use another board with this template. It requires changes in the following files.

No  |   File Name       |   To change
--- |   ---             |   ---
1   |   `.vscode/c_cpp_properties.json` | `configurations[0].defines` <br /> `configurations[0].name` <br /> `configurations[0].compilerPath`
2   |   `.vscode/launch.json` | `configurations[x].device`
3   |   `app/Makefile`  |   `LIBNAME`, `DEFS`, `FP_FLAGS`, `ARCH_FLAGS`
4   |   `app/linkerscript.ld` | `MEMORY` region & its corresponding `SECTIONS`


## Details
### c_cpp_properties
[vscode reference](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference)
- name: Mac or Linux or Win32.
- defines: Add `STM32` + model name, as this defines will be added by the compiler.
- compilerPath: your tool chain bin file path.

### Makefile Setup
For the basic device setup section, we need to cross reference with libopencm3 compiler flag to indicate the type of mcu we are using. 
- `LIBNAME`: Usually `opencm3_stm32` + model name
- `DEFS`: Usually `-DSTM32` + model name
- `FP_FLAGS`: Depends on the STM cortex model, sometimes it may include double or single precision FPU. See [libopencm3#finetuningbuilds](https://github.com/libopencm3/libopencm3#fine-tuning-the-build) for more details.
- `ARCH_FLAGS`: <TBC>

### Linkerscript
This depends on the memory region your stm32 has. Consult the memory layout data sheet and edit accordingly.