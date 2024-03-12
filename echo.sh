#!/bin/bash
function add(){
        local num1=$1
        local num2=$2
        local sum=$((num1+num2))
        echo "the sum of  $num1 and $num2 is $sum"
}

if [ $# -eq 2 ] ;
then
        add $1 $2
else
        echo "wrong parameter"
fi