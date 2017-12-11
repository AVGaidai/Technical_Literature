#!/bin/bash

CC="gcc"
CFLAGS="-Wall -ansi -pedantic -g"

PS3="Please select program to compile: "
prog=""

while [[ $prog == "" ]] ;
do
    select prog in $(ls *.c 2>/dev/null) "Quit"  ;
    do
	break
    done
done

if [[ $prog != "Quit" ]] ;
then
    $CC $CFLAGS -o ${prog%.c}.out $prog
fi

