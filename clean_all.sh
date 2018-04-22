for DIR in $(ls -d */); do
	if [[ -f "${DIR}/Makefile" ]]; then
		cd ${DIR};
		make clean
		cd ..
	else
		echo -e "\n${DIR} : No Makefile found, skipping\n";
	fi
done
