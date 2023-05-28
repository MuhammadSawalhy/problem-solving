#!/bin/bash

set -e

i=0
while true; do
  echo "$((++i))"
  ./generator $i > ./stress-inf
  ./main < ./stress-inf 2> /dev/null  1> ./stress-ouf
  touch stress-ans
  ./checker ./stress-inf ./stress-ouf ./stress-ans
done

