#!/bin/sh
start=100
step=50
end=1000
out_file="result.csv"
if [ -e ${out_file} ]
then
	yes | rm ./${out_file}
fi

#clang++ -std=c++11 ./calculate_csv.cpp -o calculate
g++ ./calculate_csv2.cpp -o calculate

for index in `seq ${start} ${step} ${end}`
do
	in_file=result${index}.csv
	./calculate ${in_file} ${index} >> ${out_file}
done

