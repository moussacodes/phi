#!/bin/sh

cd build && cmake .. && make && ./phi ../test.phi && sleep 1 && cd ..