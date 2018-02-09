#!/bin/bash
./server 8080 ./&
echo "Server aperto:localhost:8080 oppure ip:8080"
while :
do
raspistill -tl 6000 -t 999999 -vf -w 960 -h 720 -o stream/test.jpg  -n -q 50
sleep 1
done
