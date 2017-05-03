#!/bin/sh
start=100
step=50
#end=1000
end=500
num_loop=5
#file="result.csv"
dir=result

gcc -fopenmp ./a.c -lm -o a.out

for index in `seq ${start} ${step} ${end}`
do
	file=result${index}.csv
	if [ -e ./${dir}/${file} ]
	then
		yes | rm ./${dir}/${file}
	fi

#	for cnt in `seq 1 1 ${num_loop}`
#	do
#		gcc -fopenmp ./sem_mat_mat2.c -lm -o test 
#		echo "measure size: ${index}"
#		./test ${index} >> ${file}
#	done
	echo "measure size: ${index}"
	./a.out ${index} >> ./${dir}/${file}
done
