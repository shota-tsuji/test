#!/bin/sh

# 実行時に指定された引数の数，つまり変数 $# の値が 3 でなければエラー終了．
if [ $# -ne 3 ]; then
  echo "The number of arguments you put is $#" 1>&2
  echo "Please put 3 arguments for running this script." 1>&2
  exit 1
fi

# ヒアドキュメントでメッセージを表示する．
cat <<__EOT__
The $# arguments you put are
  $1,
  $2,
  $3.
__EOT__

exit 0
