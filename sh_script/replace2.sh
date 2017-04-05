for f in *.wav; do
	#echo "${f}"
	set -- $f
	common=$1
	later=$2
	mv "${f}" "${common}_${later}"
	#echo "${common}_${later}"
done
