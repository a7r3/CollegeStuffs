# CollegeStuffs - README Generator
# Yeah, I had to automate this too

cat readme_body > README.md

for DIR in $(ls -d */); do
	echo -e "\n# ${DIR//\//}\n" >> README.md;
	if [[ -f "${DIR}/generate_readme.sh" ]]; then
		cd ${DIR};
		./generate_readme.sh
		cd ..
	else
		echo -e "You're on your own\n" >> README.md;
	fi
done
