#!/bin/bash


for i in {1..50}
do
    ./gen <<< $i | ./ks >> out.txt
done


