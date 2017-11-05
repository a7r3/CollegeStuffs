# CollegeStuffs - README Generator
# Yeah, I had to automate this too

# To generate README.md : 'c' and 'java' branches should be cloned to
# 'C_DIR' and 'JAVA_DIR' respectively, under the same dir
# in which this script is present

C_DIR="c";
JAVA_DIR="java";

if [[ -f "${C_DIR}/README.md" ]]; then
	cd ${C_DIR};
	echo -e "\n# C" > README.md;

	echo -e "\n## DS\n" >> README.md;

	for file in $(ls DS/*.c); do
		PROG_INFO=$(cat $file | grep '///' | sed 's/\/\/\/ //g');
		echo -e "**${file}** - ${PROG_INFO}  \n" >> README.md;
	done

	echo -e "## SPA\n" >> README.md;

	for file in $(ls SPA/*.c); do
                PROG_INFO=$(cat $file | grep '///' | sed 's/\/\/\/ //g');
                echo -e "**${file}** - ${PROG_INFO}  \n" >> README.md;
        done
fi

cd ..;

if [[ -f "${JAVA_DIR}/README.md" ]]; then
	cd ${JAVA_DIR};
	echo -e "# Java (OOPM)\n" > README.md;

	for file in $(ls *.java); do
		PROG_INFO=$(cat $file | grep '///' | sed 's/\/\/\/ //g');
		echo -e "**${file}** - ${PROG_INFO}  \n" >> README.md;
	done
fi
