#!/bin/bash
if [ -z "$1" ]
then
  echo "provide a directory"
  exit 1
fi

if [ ! -d "$1" ]
then
  echo "provide an actual directory"
  exit 1
fi

grep -rl "define" --include \*.c $1 | sort
