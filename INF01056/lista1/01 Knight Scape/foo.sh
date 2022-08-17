#!/bin/bash

sed -n "1,9 p" $1 > l1.txt
sed -n "10,18 p" $1 > l2.txt
sed -n "19,27 p" $1 > l3.txt
sed -n "28,36 p" $1 > l4.txt
sed -n "37,45 p" $1 > l5.txt
sed -n "46,54 p" $1 > l6.txt
