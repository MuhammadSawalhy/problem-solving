#!/bin/bash

set -e

i=0

if [ $# -gt 0 ]; then
  i=$1
fi

while true; do
  echo "$((++i))"
  ./gen $i 2> /dev/null 1> ./stress-inf
  ./stress < ./stress-inf 2> /dev/null 1> ./stress-ans
  ./main < ./stress-inf 2> /dev/null  1> ./stress-ouf
  # ./checker ./stress-inf ./stress-ouf ./stress-ans
  if ! diff ./stress-ouf ./stress-ans; then
    echo
    echo "--------------------"
    echo "INPUT:"
    cat ./stress-inf
    echo
    echo "--------------------"
    echo "STRESS:"
    cat ./stress-ans
    echo
    echo "--------------------"
    echo "MAIN:"
    cat ./stress-ouf
    exit
  fi
done

