#!/bin/bash

compile() {
  g++ "$1" -o "${1%.*}"
}

compile brute-force.cpp
compile main.cpp
compile gen.cpp

# for((i = 0; i < 100; i++)); do
  # echo "i"
i=0
while true; do
  echo "$((i++))"
  ./gen "$i" > stress-in
  delta --side-by-side --line-numbers \
   <(./brute-force < stress-in 2>/dev/null) \
   <(./main < stress-in 2>/dev/null) || break
done
