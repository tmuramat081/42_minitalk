#!/bin/bash
PID=`ps | grep server | awk 'NR==1' | awk '{print $1}'`
for i in `seq 1 1000`; do 
	./client_bonus $PID $(printf %01000d $i)
done
echo "Done"
