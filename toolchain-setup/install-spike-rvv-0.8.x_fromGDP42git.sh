export RISCV=/opt/riscv
export PATH=$PATH:$RISCV/bin

sudo apt update
sudo apt install device-tree-compiler -y

git clone https://git.soton.ac.uk/gdp42/spike-riscv-isa-sim-with-vector-extensions-v0.8
cd spike-riscv-isa-sim-with-vector-extensions-v0.8/

autoconf

mkdir -p build
cd build

../configure --prefix=$RISCV
make -j16
sudo make install -j16
