#!/bin/sh

cd build && cmake .. && make && ./phi ../test.txt && sleep 1 && cd ..