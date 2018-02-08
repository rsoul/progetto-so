#!/bin/bash


pkill -f "./server 8080" 


pkill -f "./start.sh"

pkill -f "raspistill -tl 500 -t 999999 -vf -w 960 "

echo "Server killed"