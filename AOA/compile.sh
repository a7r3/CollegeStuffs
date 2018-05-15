#!/bin/bash
for file in `ls *.c`; do
    echo -e "Compiling ${file/.c/}";
    gcc -o ${file/.c/.o} ${file} ${CFLAGS} -lm;
done
