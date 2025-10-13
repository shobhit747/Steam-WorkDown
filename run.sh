#!/bin/bash

g++-11 main.cpp src/fetch_download.cpp -o main \
-I ./vcpkg_installed/x64-linux/include \
-I ./include \
-L ./vcpkg_installed/x64-linux/lib -lssl -lcrypto -O2 -march=native -DNDEBUG -lstdc++fs

./main