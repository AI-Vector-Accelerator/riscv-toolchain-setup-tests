export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin

sudo apt update
sudo apt install device-tree-compiler -y 

git clone https://github.com/riscv/riscv-isa-sim.git

mkdir -p ./riscv-isa-sim/build
cd ./riscv-isa-sim/build

../configure --prefix=$RISCV
make -j4
sudo make install -j4