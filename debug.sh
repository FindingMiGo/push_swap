rm args.txt
for ((i=0 ; i<100 ; i++))
do
echo -n $RANDOM' ' >> args.txt
done
