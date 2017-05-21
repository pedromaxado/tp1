#!/bin/bash

for file in $(seq 1000 1000 10000)
do
    echo "test_$file" >> big_tests_log.txt
    for i in $(seq 1 30)
    do
        elapsed=$(/usr/bin/time -f "%e" -a -o "big_tests_log.txt" ../tp1 < big_tests/test_$file > /dev/null)
    done
done
