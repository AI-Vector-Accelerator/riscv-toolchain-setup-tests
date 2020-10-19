#!/bin/bash
# call with first argument = 0 to checkout only
set -o pipefail
set -e

export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin

ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
VERSION="a03290eab661e2aa58288ad164f908bbbcc2169c"

sudo apt install git autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev -y

mkdir -p $RISCV

cd $RISCV

if [ -z ${NUM_JOBS} ]; then
    NUM_JOBS=4
fi

# Start Pull Stage

if ! [ -e $RISCV/bin ]; then
    if ! [ -e $RISCV/riscv-gnu-toolchain ]; then
        git clone https://github.com/riscv/riscv-gnu-toolchain.git
    fi

    cd riscv-gnu-toolchain
    git submodule init
    git submodule update --init --recursive --progress
    git checkout $VERSION

# End Pull Stage 

# Start Compilation Stage
    if [[ $1 -ne "0" || -z ${1} ]]; then
      echo "Compiling RISC-V Toolchain"
      ./configure --disable-linux --disable-multilib --disable-gdb --prefix=$RISCV --with-arch=rv32gc --with-abi=ilp32
      make -j${NUM_JOBS}
      echo "Compilation Finished"
    fi
fi
# End Compilation Stage

