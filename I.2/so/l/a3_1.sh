#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Provide the files"
    exit 1
fi

for file in "$@"; do
    counts=$(awk '
    {
        line = tolower($0)

        for (i = 1; i <= length(line); i++) {
            char = substr(line, i, 1)

            if (char ~ /[aeiou]/) {
                vowels++
            }
            else if (char ~ /[a-z]/) {
                consonants++
            }
        }
    }
    END {
        print FILENAME, vowels, consonants
    }
    ' "$file")

    echo "$counts"
done
