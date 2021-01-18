# Vanilla GNU Toolchain Setup

This directory contains shell scripts used to install the GNU RISC-V Toolchain, the Spike ISA sim, and the Spike proxy-kernal (pk).
The user has an option of building recent versions of each which don't support the RISC-V Vector ISA, or older versions which do have RVV support.

## Running the Scripts

The scripts in this directory have been tested on a fresh WSL 2 Ubuntu VM run in the following order:

### Standard Toolchain 

1. `sudo ./install-riscv-gcc.sh`
2. `sudo ./install-spike.sh`
3. `sudo ./install-pk.sh  `

### Vector Toolchain

1. `./install-rvv-0.8.x.sh
2. `./install-spike-rvv-0.8.x_fromRISCVgit.sh`
3. `./install-pk.sh`

These scripts will install the GNU RISC-V toolchain in the directory /opt/riscv.

<b>Be warned:</b> The RISCV GNU Toolchain has a huge codebase distributed over many repositories. It will take a lot of time and compute effort to collect and build. During testing the WSL 2 process used up to 11 GB of RAM. It is recommended that you close any non-essential processes before starting the script.

At the end of the installation process the process still had claim over ~10 GB even with all bash terminals closed. It is recommended that you restart your computer after installing the toolchain. 



## Setting Up PATH

To use the toolchain from anywhere in your filesystem you must add `/opt/riscv/bin` to your PATH environment variable. This will tell bash to look in this directory whenever you enter a command into the terminal. You can do this for your current session by running the following commands:

```bash
export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin
export CV32SIM=$HOME/core-v-verif/cv32/sim/core
export PATH=$PATH:$CV32SIM

```

However this change will be undone when you close your terminal. To make the change permanent you must add the commends above to your `~/.profile` file.
Open the file with the command:
```bash
nano ~/.profile
```
Copy and paste the export commands above to the bottom of the file.  
The bottom of your `~/.profile` file should now look something like this:
```bash
...
# set PATH so it includes user's private bin if it exists
if [ -d "$HOME/bin" ] ; then
    PATH="$HOME/bin:$PATH"
fi

# set PATH so it includes user's private bin if it exists
if [ -d "$HOME/.local/bin" ] ; then
    PATH="$HOME/.local/bin:$PATH"
fi

export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin

export CV32SIM=$HOME/core-v-verif/cv32/sim/core
export PATH=$PATH:$CV32SIM
```

