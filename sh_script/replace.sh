for f in *.wav; do
	#echo ${f// /_}
	set -- $f
	common=$1
	later=$2
	#new_file=`echo $f | sed 's/ *//g'`
	#new_file=${common}_${later}
	#rename ${f} ./${f// /_}
	#mv $f ./$new_file
	#mv $f ${new_file}
	#echo $1\ $f
	rename ${common}\ ${common}_ $f
done
