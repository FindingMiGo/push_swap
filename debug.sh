#!/usr/bin/bash
for i in {1..100}
do
	echo -n $i' '
	ARG=`seq -100 100 | shuf | head -n 100 | xargs echo`
	echo $ARG > arg.txt
	./push_swap $ARG > result.txt
	cat result.txt | ./checker_linux $ARG | tr '\n' ' '
	NUM1=`cat result.txt | wc -l`
	echo -n $NUM1
	if [ $NUM1 -ge 700 ]; then
		echo -e ' Oooops!'
		cat arg.txt > cmp.txt
		cat result.txt >> cmp.txt
		break
	fi
	echo -e
done
rm arg.txt result.txt
