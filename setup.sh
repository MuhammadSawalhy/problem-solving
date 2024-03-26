#!/bin/bash

link_file() {
    ln -sf "$(realpath "$1")" "$2"
}

# headers to include directory
link_file ./debug.hpp /usr/local/include
link_file ./testlib.h /usr/local/include

# scripts to bin directory
link_file ./.stress-testing/stress         /usr/local/bin
link_file ./.stress-testing/interact       /usr/local/bin
link_file ./.stress-testing/stress-files   /usr/local/bin
link_file ./.stress-testing/interact-files /usr/local/bin

