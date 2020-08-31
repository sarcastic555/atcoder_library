#!/bin/bash

INPUTFILE=${1:-"input.txt"}
alphabet=("a" "b" "c" "d" "e" "f" "g" "h" "i" "j" "k")
alphabet=("a" "b" "c" "d")
A=""
B=""
SIZE=`expr ${RANDOM} % 4 + 2`
for i in `seq ${SIZE}`; do
    rand=`expr ${RANDOM} % ${#alphabet[*]}`
    A+=${alphabet[$rand]}
    rand=`expr ${RANDOM} % ${#alphabet[*]}`
    B+=${alphabet[$rand]}
done
echo $A > ${INPUTFILE}
echo $B >> ${INPUTFILE}
