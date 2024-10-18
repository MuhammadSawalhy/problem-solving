#!/bin/bash

link_file() {
  ln -sf "$(realpath "$1")" "$(realpath "$2")"
}

sudo_link_file() {
  sudo ln -sf "$(realpath "$1")" "$(realpath "$2")"
}

link_file ./cpp.snippets ~/.config/nvim/snippets/cpp.snippets

# headers to include directory
sudo_link_file ./debug.hpp /usr/local/include
sudo_link_file ./testlib.h /usr/local/include

# scripts to bin directory
sudo_link_file ./.stress-testing/stress         /usr/local/bin
sudo_link_file ./.stress-testing/interact       /usr/local/bin
sudo_link_file ./.stress-testing/stress-files   /usr/local/bin
sudo_link_file ./.stress-testing/interact-files /usr/local/bin

