export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin

sudo apt update
sudo apt install device-tree-compiler -y

git clone https://github.com/riscv/riscv-isa-sim.git
cd riscv-isa-sim

git checkout 220ae7ec6b9bf4a5d81190ffa1028438c3cf402b
git branch

mkdir -p build
cd build

../configure --prefix=$RISCV
make -j16
sudo make install -j16
