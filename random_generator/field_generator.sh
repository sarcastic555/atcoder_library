#!/bin/bash

###############
#  6 3
#  .##
#  ..#
#  ..#
#  ##.
#  #..
#  ##.
###############


INPUTFILE=${1:-"input.txt"}

H=`expr ${RANDOM} % 7 + 1`
W=`expr ${RANDOM} % 7 + 1`

echo ${H} ${W} > ${INPUTFILE}
for i in `seq ${H}`; do
    STRING=""
    for j in `seq ${W}`; do
	ZEROONE=`expr ${RANDOM} % 2`
	if [ ${ZEROONE} -eq 0 ]; then
	    STRING=${STRING}"."
	else
	    STRING=${STRING}"#"
	fi
    done
    if [ $i -eq 1 ]; then
	echo "."${STRING:1:${W}-1} >> ${INPUTFILE}
    else
	echo ${STRING} >> ${INPUTFILE}
    fi
done

	 
