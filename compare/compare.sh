#!/bin/bash

INPUTFILE="${PWD}/input.txt"
TARGET1="test.cpp"
TARGET2="test2.cpp"
RESULTDIR="result"
OUT1="${RESULTDIR}/test.out"
OUT2="${RESULTDIR}/test2.out"
RESULT1="${RESULTDIR}/out.txt"
RESULT2="${RESULTDIR}/out2.txt"

mkdir -p ${RESULTDIR}
g++ -std=c++17 ${TARGET1} -o ${OUT1}
g++ -std=c++17 ${TARGET2} -o ${OUT2}

count=1
while true; do
    # Generate random input
    ./random_generator/generate_random_tree.sh ${INPUTFILE}
    echo "====== Trial ${count} ====="
    echo "Input===:"
    cat ${INPUTFILE}

    # Execution
    ./${OUT1} < ${INPUTFILE} > ${RESULT1}
    ./${OUT2} < ${INPUTFILE} > ${RESULT2}

    # Check diff
    diffcount=`diff -u ${RESULT1} ${RESULT2} | wc -l`
    if [ $diffcount -ne 0 ]; then
	echo "Diff found===:"
	diff -u ${RESULT1} ${RESULT2}
	return
    fi
    sleep 0.1
    count=`expr $count + 1`
done
