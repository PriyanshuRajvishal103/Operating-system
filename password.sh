#!/bin/bash
clear
read -p "enter your name please: " name
if [ "$name" = "vishal" ];
then
        echo "Welcome"
else
        echo "wrong id"
fi