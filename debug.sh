#!/usr/bin/bash
ARG=`seq -100 100 | shuf | head -n 100 | xargs echo`;
echo $ARG > args.txt
