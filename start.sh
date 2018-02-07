#!/bin/bash
while :
do
raspistill -tl 500 -t 999999 -vf -w 960 -h 720 -o stream/test.jpg -n -q 50
sleep 1
done
