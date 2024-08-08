#!/bin/bash

i=0

if [ $# -gt 0 ]; then
  i=$1
fi

while true; do
  echo "$((++i))"
  ./gen $i 2> /dev/null 1> ./stress-inf

  if [ -f validate ]; then
    ./validate < ./stress-inf ||
      { echo && echo "ERROR: validtor failed" >&2 && exit 1; }
  fi

  ./stress < ./stress-inf 2> /dev/null 1> ./stress-ans
  ./main < ./stress-inf 2> /dev/null  1> ./stress-ouf

  if [ -f check ]; then
    ./check ./stress-inf ./stress-ouf ./stress-ans
  else
    diff ./stress-ouf ./stress-ans
  fi

  if (($?)); then
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

