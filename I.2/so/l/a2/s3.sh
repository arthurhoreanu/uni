#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Please provide the text and the files"
  exit 1
fi

text=$1
shift

for file in "$@"; do
  if [ ! -f "$file" ]; then
    echo "File not found: $file"
    continue
  fi
  sed '1,30 d/ADT/g' "$file"
done
