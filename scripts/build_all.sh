#!/bin/bash

echo "Building all solutions..."
mkdir -p build
cd build
cmake ..
make -j$(nproc)
echo "Build completed!"