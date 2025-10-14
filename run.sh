#!/bin/bash

g++-11 main.cpp ./src/fetch_download.cpp ./src/gui_interface.c ./src/fetch_download_wrapper.cpp -o main \
-I ./vcpkg_installed/x64-linux/include \
-I ./include $(pkg-config --cflags gtk+-3.0) \
-L ./vcpkg_installed/x64-linux/lib -lssl -lcrypto $(pkg-config --libs gtk+-3.0) -Wl,-export-dynamic -O2 -march=native -DNDEBUG -lstdc++fs

./main

# g++-11 $(pkg-config --cflags gtk+-3.0) -g  main.cpp -o demo_gui $(pkg-config --libs gtk+-3.0) -export-dynamic