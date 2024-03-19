#!/bin/bash

if [ -z "$1" ]
then
  echo "Directory name not provided"
  exit 1
fi

dir_path="$1"

ls -l "$dir_path"
echo 
ls -lt "$dir_path"
echo
ls -lS "$dir_path"
