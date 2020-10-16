# Basic RISC-V Test Programs

This repository contains programs that can be used to verify toolchain configuration for compiling bare-metal programs for the CV32E40P RISC-V reference core.

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

## Running the Programs
The test programs are stored in sub-directories. To run a program navigate to its sub-directory and call `make all` to build the hex file of the program and run it on the Verilog model. 
