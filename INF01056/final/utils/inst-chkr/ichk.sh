#!/bin/bash

if [ -z $1 ]
then
    echo "usage: $0 [ agreeable | normal ]"
    exit
fi

if [[ "$1" != agreeable && "$1" != normal ]]
then
    echo "usage: $0 [ agreeable | normal ]"
    exit
fi

DIR='/home/fscorrea/final/inst'

for n in {70..100..10} ; do
    for p in {5..30..5} ; do
	for i in {1..50} ; do
	    ./inst-chkr "$DIR/$1/$n/$p/$i.in" >> "$DIR/$1/$n/$p/instchk.out"	    
	done
    done
done
