#!/bin/bash
g++ -std=c++17 -Wall -Werror conways.cc -o conways
./conways < $1.in > $1.out