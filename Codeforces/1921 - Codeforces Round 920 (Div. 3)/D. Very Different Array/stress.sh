#!/bin/bash

set -e

i=0
while true; do
  echo "$((++i))"
  ./generator $i 2> /dev/null 1> ./stress-inf
  ./stress < ./stress-inf 2> /dev/null 1> ./stress-ans
  ./main < ./stress-inf 2> /dev/null  1> ./stress-ouf
  # ./checker ./stress-inf ./stress-ouf ./stress-ans
  if ! diff ./stress-ouf ./stress-ans; then
    echo
    echo "--------------------"
    echo "INPUT:"
    cat ./stress-inf
  fi
done

