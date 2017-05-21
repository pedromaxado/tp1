#!/bin/bash

for size in $(seq 10 10 50)
do
    for file in testes/$size/*.txt
    do
        echo "$file" >> log_aleatorios.txt
        for i in $(seq 1 10)
        do
            /usr/bin/time -f "%e" -a -o "log_toys.txt" ./tp0 < $file > /dev/null
        done
    done
done
