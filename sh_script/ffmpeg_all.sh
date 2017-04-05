for f in *.3gp; do
	f_without_ext=${f%.*}
	ffmpeg -i ${f} ${f_without_ext}.ogg

	departure=~/Music/dump
	mv -v ${f} ${departure} 
done
