#!/bin/bash
set -eu

INPUTFILE="${PWD}/input.txt"
TARGET1="test.cpp"
TARGET2="test2.cpp"
OUT1="test.out"
OUT2="test2.out"
RESULT1="out.txt"
RESULT2="out2.txt"

g++ ${TARGET1} -o ${OUT1}
g++ ${TARGET2} -o ${OUT2}

while true; do
    echo ${INPUTFILE}
    #source ./random_generator/field_generator.sh ${INPUTFILE}
    #source ./random_generator/string_generator.sh ${INPUTFILE}
    source ./random_generator/integer_array_generator.sh ${INPUTFILE}

    echo "====== show input start ===="
    cat ${INPUTFILE}
    echo "====== show input end ===="
    ./${OUT1} < ${INPUTFILE} > ${RESULT1}
    ./${OUT2} < ${INPUTFILE} > ${RESULT2}
    echo "=== diff output start ==="
    diff -u ${RESULT2} ${RESULT2}
    echo "=== diff output end ==="
    diffcount=`diff -u ${RESULT1} ${RESULT2} | wc -l`
    if [ $diffcount -ne 0 ]; then
	break
    fi
    sleep 0.1
done
