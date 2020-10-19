# Vanilla GNU Toolchain Setup

This directory contains shell scripts used to install the GNU RISC-V Toolchain, the Spike ISA sim, and the Spike proxy-kernal (pk).

## Running the Scripts

The scripts in this directory have been tested on a fresh WSL 2 Ubuntu VM run in the following order:

1. sudo install-riscv-gcc.sh
2. sudo install-spike.sh
3. sudo install-pk.sh  

They can be run by:

```bash
sudo ./install-riscv-gcc.sh 
```

These scripts will install the GNU RISC-V toolchain will be installed into the standard location (/opt/riscv).

<b>Be warned:</b> The RISCV GNU Toolchain has a huge codebase distributed over many repositories. It will take a lot of time and compute effort to collect and build. During testing the WSL 2 process used up to 11 GB of RAM. It is recommended that you close any non-essential processes before starting the script.

At the end of the installation process the process still had claim over ~10 GB even with all bash terminals closed. It is recommended that you restart your computer after installing the toolchain. 

## Setting Up PATH

To use the toolchain from anywhere in your filesystem you must add `/opt/riscv/bin` to your PATH environment variable. This will tell bash to look in this directory whenever you enter a command into the terminal. You can do this for your current session by running the following command:

```bash
export PATH=$PATH:/opt/riscv/bin
```

However this change will be undone when you close your terminal. To make the change permanent add this command to the bottom of the file `~/.profile`:
```bash
echo export PATH=$PATH:/opt/riscv/bin >> ~/.profile
```
