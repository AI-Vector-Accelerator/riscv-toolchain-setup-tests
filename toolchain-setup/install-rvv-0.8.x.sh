#!/bin/bash
# call with first argument = 0 to checkout only

export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin

sudo apt install git autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev -y

mkdir -p $RISCV
cd $RISCV

echo "Starting cloning stage"

git clone -b rvv-0.8.x https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain
git submodule update --init --recursive --progress --jobs=16

echo "Finished cloning stage"

echo "Obtaining different version of new lib"

# Checkout less broken version of newlib
cd riscv-newlib
git checkout 3e5302714fae99acc8c439f5870846312d081631
cd ..

echo "Obtained different version of new lib"


echo "Compiling RISC-V vector extension 0.8 Toolchain"
./configure --disable-linux --disable-multilib --disable-gdb --prefix=$RISCV --with-arch=rv32imc --with-abi=ilp32
make -j16
echo "Compilation Finished"
