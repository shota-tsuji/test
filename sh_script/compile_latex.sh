#!/bin/sh

CMDNAME=`basename $0`
if [ $# -ne 1 ]; then
  echo "Usage: $CMDNAME pdf_title" 1>&2
  exit 1
fi

TITLE=$1
FILE_TEX=${TITLE}.tex

platex $FILE_TEX
makeglossaries $TITLE
platex $FILE_TEX
dvipdfmx $TITLE

FILE_PDF=${TITLE}.pdf
evince $FILE_PDF &

#date '+%D' >$1
#date '+%R' >$2

#echo "Check created files ..."
#ls -l $1 $2

exit 0
