#!/bin/bash

compile() {
  echo compiling: "$1"
  g++ -DSAWALHY "$1" -o "${1%.*}"
}

compile stress.cpp
compile main.cpp
compile gen.cpp

# for((i = 0; i < 100; i++)); do
  # echo "i"
i=0
while true; do
  echo "$((++i))"
  ./gen "$i" 2> /dev/null 1> main-in
  ./main < main-in 2> /dev/null 1> main-out
  ./stress < <(cat main-in main-out) || break
done
