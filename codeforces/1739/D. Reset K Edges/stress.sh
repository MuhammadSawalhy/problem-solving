#!/bin/bash

compile() {
  g++ "$1" -o "${1%.*}"
}

compile brute-force.cpp
compile main.cpp
compile gen.cpp

for((i = 0; i < 100; i++)); do
  echo "$i"
  ./gen "$i" > stress-in
  diff <(./brute-force < stress-in) <(./main < stress-in) || break
done
