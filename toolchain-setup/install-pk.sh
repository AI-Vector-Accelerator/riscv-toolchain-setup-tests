export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin

git clone https://github.com/riscv/riscv-pk.git

mkdir -p ./riscv-pk/build
cd ./riscv-pk/build

../configure --prefix=$RISCV --host=riscv32-unknown-elf
make -j4
make install 