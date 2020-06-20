#!/bin/bash

INPUTFILE="${PWD}/input.txt"

g++ test.cpp -o test.out
g++ test3.cpp -o test3.out

while true; do
    echo ${INPUTFILE}
    #source ./random_generator/field_generator.sh ${INPUTFILE}
    source ./random_generator/string_generator.sh ${INPUTFILE}

    echo "====== show input start ===="
    cat ${INPUTFILE}
    echo "====== show input end ===="
    ./test.out < ${INPUTFILE} > out.txt
    ./test3.out < ${INPUTFILE} > out3.txt
    echo "=== diff output start ==="
    diff -u out.txt out3.txt
    echo "=== diff output end ==="
    diffcount=`diff -u out.txt out3.txt | wc -l`
    if [ $diffcount -ne 0 ]; then
	break
    fi
    sleep 0.1
done
