#!/usr/bin/bash
ARG=`seq -100 100 | shuf | head -n 7 | xargs echo`;
echo $ARG > log.txt
./push_swap $ARG > result.txt
