#!/bin/sh
start=100
step=50
end=1000
num_loop=5
file="result.csv"
for index in `seq ${start} ${step} ${end}`
do
	file=result${index}.csv
	if [ -e ${file} ]
	then
		yes | rm ./${file}
	fi

	for cnt in `seq 1 1 ${num_loop}`
	do
		gcc -fopenmp ./sem_mat_mat2.c -lm -o test 
		echo "measure size: ${index}"
		./test ${index} >> ${file}
	done
done
