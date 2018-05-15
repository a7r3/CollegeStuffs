#!/bin/bash

for file in `ls *.java`; do
	echo -e "\n[!] Compiling $file\n";
	javac "$file";
done

