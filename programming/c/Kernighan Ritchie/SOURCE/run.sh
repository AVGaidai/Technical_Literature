#!/bin/bash

PS3="Please select program to run: "
prog=""

while [[ $prog == "" ]] ;
do
    select prog in $(ls  *.out 2>/dev/null) "Quit" ;
    do
	break
    done
done

if [[ $prog != "Quit" ]] ;
then
    ./$prog
fi
