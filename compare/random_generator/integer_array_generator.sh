#!/bin/bash

# 2以上MAXSIZE+2以下のランダムな要素数の数だけ
# 1以上MAXVALUE以下の整数配列を生成する
# ex
# 4
# 1 5 4 2

INPUTFILE=${1:-"input.txt"}
MAXSIZE=8
MAXVALUE=20

SIZE=`expr ${RANDOM} % ${MAXSIZE} + 2`
echo $SIZE > ${INPUTFILE}
for i in `seq ${SIZE}`; do
    rand=${RANDOM}
    denomerator=`expr ${SIZE} - 1`
    value=`expr ${rand} % ${denomerator} + 1`
    echo $value >> ${INPUTFILE}
done

