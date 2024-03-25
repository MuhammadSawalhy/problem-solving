#!/bin/bash

ln -sf "$(realpath ./debug.hpp)" /usr/local/include
ln -sf "$(realpath ./testlib.h)" /usr/local/include
ln -sf "$(realpath ./.stress-testing/stress)" /usr/local/bin
ln -sf "$(realpath ./.stress-testing/stress-files)" /usr/local/bin
