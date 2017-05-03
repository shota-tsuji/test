#!/bin/sh
start=100
step=1
end=150
file="result.csv"

if [ -e ${file} ]
then
	yes | rm ./${file}
fi

gcc -fopenmp ./c.c -o a.out 
for index in `seq ${start} ${step} ${end}`
do
	echo "measure size: ${index}"
	./a.out ${index} >> ${file}
done
