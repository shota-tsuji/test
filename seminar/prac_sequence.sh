#!/bin/sh
start=100
step=50
end=1000
file="result.csv"
if [ -e ${file} ]
then
	yes | rm ./${file}
fi

for i in `seq ${start} ${step} ${end}`
do
	./test $i >> ${file}
done
