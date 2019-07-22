#!/bin/bash

DIR="$(cd $(dirname "$0"); pwd)/../.."

cd stub
mkdir -p build
cd build
cd .. ; rm -rf build ; mkdir build; cd build; cmake .. -DCODEGEN="$DIR/gdbus-codegen-glibmm.py" -DCMAKE_BUILD_TYPE=Debug
make
./stubtest &
STUB_PID=$!

trap 'kill $STUB_PID' EXIT

cd ../../proxy
mkdir -p build
cd build
cd .. ; rm -rf build ; mkdir build; cd build; cmake .. -DCODEGEN="$DIR/gdbus-codegen-glibmm.py" -DCMAKE_BUILD_TYPE=Debug

make
./proxytest
