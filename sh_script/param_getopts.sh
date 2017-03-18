#!/bin/bash

CMDNAME=`basename $0`

while getopts ab:c: OPT
do
  case $OPT in
    "a" ) FLG_A="TRUE" ;;
    "b" ) FLG_B="TRUE" ; VALUE_B="$OPTARG" ;;
    "c" ) FLG_C="TRUE" ; VALUE_C="$OPTARG" ;;
       * ) echo "Usage: $CMDNAME [-a] [-b VALUE] [-c VALUE]" 1>&2
            exit 1 ;;
  esac
done

if [ "$FLG_A" = "TRUE" ]; then
  echo `"-a" option was selected.`
fi

if [ "$FLG_B" = "TRUE" ]; then
  echo `"-a" option was selected. `
  echo "The value is $VALUE_B."
fi

if [ "$FLG_C" = "TRUE" ]; then
  echo `"-a" option was selected. `
  echo "The value is $VALUE_C."
fi

exit 0
