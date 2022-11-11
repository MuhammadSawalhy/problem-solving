#!/bin/bash

if [ ! -t 0 ]; then
  cat > stress-in
  delta --side-by-side \
   <(./stress < stress-in 2>/dev/null) \
   <(./main < stress-in 2>/dev/null)
  exit 0
fi

compile() {
  echo compiling: "$1"
  g++ "$1" -o "${1%.*}"
}

compile stress.cpp
compile main.cpp
compile gen.cpp

# for((i = 0; i < 100; i++)); do
  # echo "i"
i=0
while true; do
  echo "$((++i))"
  ./gen "$i" > stress-in
  delta --side-by-side \
   <(./stress < stress-in 2>/dev/null) \
   <(./main < stress-in 2>/dev/null) || break
done
