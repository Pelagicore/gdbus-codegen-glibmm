#!/bin/bash

DIR=$(cd $(dirname "$0"); pwd)

cd stub
mkdir -p build
cd build
cd .. ; rm -rf build ; mkdir build; cd build; cmake .. -DCODEGEN=$DIR/../gdbus-codegen-glibmm.py
make
./stubtest &
STUB_PID=$!

cd ../../proxy
mkdir -p build
cd build
cd .. ; rm -rf build ; mkdir build; cd build; cmake .. -DCODEGEN=$DIR/../gdbus-codegen-glibmm.py
make
./proxytest&
PROXY_PID=$!

sleep 1

kill $PROXY_PID
kill $PROXY_PID
