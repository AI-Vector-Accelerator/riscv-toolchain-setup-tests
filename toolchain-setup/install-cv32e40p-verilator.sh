#!/bin/bash

export CV32SIM=$HOME/core-v-verif/cv32/sim/core
export PATH=$PATH:$CV32SIM

cd $HOME

sudo apt install verilator
git clone https://github.com/openhwgroup/core-v-verif.git


cd ./core-v-verif/cv32/sim/core
make -j16    # Clone the CV32E40P, build the Verilator model, run a bare-metal hello-world example

echo ""
echo "Add $CV32SIM to your enviromental paths using nano ~/.profile"





