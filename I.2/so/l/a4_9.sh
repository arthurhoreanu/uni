#!/bin/bash

if [ $# -ne 3 ]
then
    echo "Please provide 3 parameters: directory, function and replaceparameter"
    exit 1
fi

dir=$1
fun=$2
par=$3

if [ ! -d "$dir" ]
then
    echo "Please provide a valid directory"
    exit 1
fi

count=0

for file in $dir/*.c
do
    if [ -f "$file" ]
    then
        changed_lines=$(grep -n "$fun" "$file" | grep -E "(\b$fun\s*\([^)]*\);)" | sed "s/$fun/$par/g")
        occurrences=$(echo "$changed_lines" | wc -l)
        if [ "$occurrences" -gt 0 ]; then
            echo "Lines changed:"
            echo "$changed_lines"
            count=$((count + occurrences))
        fi
    fi
done

echo "Number of changes: $count"
