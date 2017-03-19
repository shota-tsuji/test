#!/bin/bash
for filename in *; do
  # Check the file if it is .3gp file or not.
  extname=${filename##*.}
  if [ "${extname}" == "3gp" ]; then
    filename_without_ext=${filename%.*}
    echo ${filename_without_ext}
    ffmpeg -i ${filename} ${filename_without_ext}.ogg
  fi
  sleep 1;
done
