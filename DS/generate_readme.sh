for file in $(ls *.c); do
	PROG_INFO=$(cat $file | grep '///' | sed 's/\/\/\/ //g');
	echo -e "**${file}** - ${PROG_INFO}  \n" >> ../README.md;
done
