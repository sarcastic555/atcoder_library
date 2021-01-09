#!/bin/bash

# This first creates input corresponding to tree structure, then selects a pair of nodes
#
# ===== Format =====
# N
# x_1 y_1
# x_2 y_2
# ...
# x_N-1 y_N-1
# 1
# x y
# ==================
# Ref: https://atcoder.jp/contests/abc014/tasks/abc014_4

## Parameters
OUTFILE=$1
SCRIPTDIR=$(cd $(dirname $0); pwd)
N=16

## Compile
g++ -std=c++17 ${SCRIPTDIR}/tree_generator.cpp -o ${SCRIPTDIR}/tree_generator.out

## Main
echo $N > $OUTFILE
${SCRIPTDIR}/tree_generator.out $N $OUTFILE
echo 1 >> $OUTFILE
rand1=`expr ${RANDOM} % ${N} + 1`
rand2=`expr ${RANDOM} % ${N} + 1`
while [ $rand1 -eq $rand2 ]; do
    rand1=`expr ${RANDOM} % ${N} + 1`
    rand2=`expr ${RANDOM} % ${N} + 1`
done
echo $rand1 $rand2 >> $OUTFILE

