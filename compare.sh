#!/bin/bash

INPUTFILE="input.txt"

g++ test.cpp -o test.out
g++ test2.cpp -o test2.out

./random_generator/field_generator.sh ${INPUTFILE}

cat ${INPUTFILE}
./test.out < ${INPUTFILE} > out.txt
./test2.out < ${INPUTFILE} > out2.txt

diff -u out.txt out2.txt
	 
