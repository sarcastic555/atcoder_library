#!/bin/bash
#set -eu

INPUTFILE="${PWD}/input.txt"

cp work/test.cpp .
cp work/test2.cpp .

g++ -std=c++11 test.cpp -o test.out
g++ -std=c++11 test2.cpp -o test2.out

## Compile random generator
cd random_generator
g++ generate.cpp
if [ $? -gt 0 ]; then
    # エラー処理
    echo "Compile error"
fi
cd -

while true; do
    ./random_generator/a.out > ${INPUTFILE}

    echo "====== show input start ===="
    cat ${INPUTFILE}
    echo "====== show input end ===="
    ./test.out < ${INPUTFILE} > out.txt
    ./test2.out < ${INPUTFILE} > out2.txt
    echo "=== diff output start ==="
    diff -u out.txt out2.txt
    echo "=== diff output end ==="
    diffcount=`diff -u out.txt out2.txt | wc -l`
    echo "diff1="$diffcount
    if [ $diffcount -ne 0 ]; then
    echo "diff2="$diffcount
	break
    fi
    #sleep 0.1
done
