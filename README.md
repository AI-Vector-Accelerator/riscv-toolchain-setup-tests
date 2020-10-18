# Basic RISC-V Test Programs

This repository contains programs used to demonstrate the compilation of bare-metal programs for the CV32E40P RISC-V reference core in preparation for compiling the existing tinyMLperf benchmarking suite.

## Prerequisites
### Toolchain
The PULP-Platform RISC-V GCC compiler is recommended for use with this core.
The toolchain can be installed by following the instructions linked below:  
https://github.com/openhwgroup/core-v-verif/blob/master/cv32/sim/TOOLCHAIN.md  

Other RISC-V toolchains may work but they have not been tested. 

### Simulator
The CV32E40P is currently undergoing verification in preparation for tape-out.
Part of this verification process is exercising a Verilator model of the processor.
This Verilator model can be initialized with an arbitrary hex file loaded into memory. 
This model is used to run the example programs.

Run the commands below to generate the Verilator model of the CV32E40P.

```bash
git clone https://github.com/openhwgroup/core-v-verif.git
cd ./core-v-verif/cv32/sim/core
make    # Clone the CV32E40P, build the Verilator model, run a bare-metal hello-world example
```

Add the simulator to your PATH for easy access elsewhere in your system making sure you replace `/path/to` in the first statement with the full path to the core-v-verif repo.

```bash
echo export CV32SIM=/path/to/core-v-verif/cv32/sim/core >> ~/.profile
echo export PATH=$PATH:$CV32SIM >> ~/.profile
```

To increase the speed of the model go to the file `./core-v-verif/cv32/tb/core/tb_top_verilator.cpp` and remove the call to `dump_memory();` in `main()` and rebuld the simulator. This will stop the simulator dumping its memory before it has run any code, dramatically reducing the time needed to start the simulation. 

## Running the Programs
The test programs are stored in sub-directories. To run a program navigate to its sub-directory and call `make all` to build the hex file of the program and run it on the Verilog model. 

## Build System 
The build system used in these example programs is the same as is used to compile the test programs in the core-v-verif repo. 
Details on this build system can be found here:
https://github.com/openhwgroup/core-v-verif/tree/master/cv32/bsp#building-and-using-the-bsp-library

In each program sub-directory there is a lib directory.
This directory contains the files `libcv-verif.a` and `link.ld`.

### libcv-verif.a
This archive file contains bare-metal implementations of essential functions usually provided by the OS. 
It includes a port of the C Runtime (crt0.S), a port of syscalls that does not rely on an OS, an interrupt system, and a vector table.  

The syscall port is pretty bare-bones, the lack of an OS means the best many of the syscall functions can do is fail gracefully (e.g: file handling). 
Initial experimentation showed that the toolchain can sometimes try to add two different versions of syscalls if standard C functions are called from libraries other than stdio.h or stdlib.h, e.g: time.h.

TODO: Investigate recompiling `libcv-verif.a` without the proprietary syscalls and letting GCC link in the default version. 

### link.ld
This is the linker script used to arrange the sections correctly in the ELF and HEX files produced at the end of compilation. It has been slightly edited from the default RISC-V linker script to accommodate changes in the address space in the CV32E40P.
It is used to place the C Runtime start up code at the correct address. 
When this linker script is not used GCC makes incorrect assumptions about where to put the boot code. Often it will assume the program is being built to run on top of Linux and place the boot code accordingly.   

### Usage 
Below is an example taken from the core-v-verif repo of how the above files should be used during the build process:  
```sh
gcc test-program.o extra1.o extra2.o \
     -nostartfiles -T/path/to/link/link.ld -L/path/to/cv-verif/ -lcv-verif
```

The `-nostartfiles` flag tells GCC not to include the default C Runtime boot code.  
The `-T` option allows a user to specify the linker script used.  
The `-L` option is used to tell GCC where to look for library files and the `-l` option is used to indicate an archive file to link into the project. 

These extra options are only required when linking. Object files can be produced without these options. 

### Compiling and Linking Options
On top of the options discussed in [Usage](#usage), other compilation and linking options are required to get code running bare-metal.  
Below is an excerpt from the makefile in the helloworld sub-directory.
It shows the options used to compile each object files (`RV_COMPILER_OPTIONS`) and the compiler options used in the final linking stage (`RV_LINKING_OPTIONS`). 
The linking options are largely the same as the compilation options with the `-nostartfiles` flag added to the end. 

```make
RV_COMPILER_OPTIONS = -Os -g -static -mabi=ilp32 -march=rv32imc -Wall -pedantic 
RV_LINKING_OPTIONS = ${RV_COMPILER_OPTIONS} -nostartfiles
```


