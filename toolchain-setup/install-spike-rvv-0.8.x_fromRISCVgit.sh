export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin

sudo apt update
sudo apt install device-tree-compiler -y

git clone https://github.com/riscv/riscv-isa-sim.git
cd riscv-isa-sim

git checkout 220ae7e
git branch

mkdir -p build
cd build

sudo ../configure --prefix=$RISCV
make -j16
sudo make install -j16
