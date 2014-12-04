#!/bin/bash

DIR=$(cd $(dirname "$0"); pwd)

cd stub
mkdir -p build
cd build
cd .. ; rm -rf build ; mkdir build; cd build; cmake .. -DCODEGEN=$DIR/../gdbus-codegen-glibmm.py -DCMAKE_BUILD_TYPE=Debug
make
./stubtest &
STUB_PID=$!

cd ../../proxy
mkdir -p build
cd build
cd .. ; rm -rf build ; mkdir build; cd build; cmake .. -DCODEGEN=$DIR/../gdbus-codegen-glibmm.py -DCMAKE_BUILD_TYPE=Debug

make
./proxytest&
PROXY_PID=$!

sleep 1

kill $STUB_PID
kill $PROXY_PID
