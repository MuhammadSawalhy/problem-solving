#!/bin/bash

set -e

i=0
while true; do
  echo "$((++i))"
  ./generator --valid --size 10 --ymin 0 $i 2> /dev/null 1> ./stress-inf
  ./stress < ./stress-inf 2> /dev/null 1> ./stress-ans
  ./ans < ./stress-inf 2> /dev/null  1> ./stress-ouf
  # ./checker ./stress-inf ./stress-ouf ./stress-ans
  diff ./stress-ans ./stress-ouf
done

