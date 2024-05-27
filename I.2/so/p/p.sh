#!/bin/bash

if [ -z "$1" ]; then
  echo "Nu ați introdus un director."
  exit 1
fi

find "$1" | sort | uniq
