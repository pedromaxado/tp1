#!/bin/bash

ratio=$1

for size in $(seq 10000 10000)
do
    edges=$(bc <<< "$size*($size-1)*$ratio / 2")
    echo "$size $edges" > test_$size
    ./graph.py -uk -e $edges $size >> test_$size
done

#vertices=$1
#ratio=$2
#edges=$(bc <<< "($vertices*($vertices-1)*$ratio) / 2")
#echo "$vertices $edges"
#./graph.py -uk -e $edges $vertices
