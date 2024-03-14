#!/bin/bash
clear
read -p "enter two number" num1 num2
if [ "$num1" -eq "$num2" ];
then
        echo "both the number are equal"
else
        if [ "$num1" -gt "$num2" ];
        then
                echo "$num1 is greater than $num2"
        else
                echo "$num1 is smaller than $num2"
        fi
fi