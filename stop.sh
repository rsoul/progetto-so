#!/bin/bash
pid_server=pidof./server 8080

kill $pid_server

echo "Server killed"