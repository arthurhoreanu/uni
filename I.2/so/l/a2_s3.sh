#!/bin/bash

if [ $# -lt 2 ]; then
  echo "Please provide the text and the files"
  exit 1
fi

text=$1

for file in "${@:2}"; do
  if [ ! -f "$file" ]; then
    echo "File not found: $file"
    continue
  fi
  sed "1,30 s/$text//g" "$file"
done
