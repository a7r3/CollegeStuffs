init:
	@echo "##########################"
	@echo "# CollegeStuffs! by a7r3 #"
	@echo "##########################"
	@echo
compilemsg:
	@echo "[!] Compiling all Programs"
	@echo
	bash ./compile_all.sh

collegestuffs: init compilemsg $(OUTPUT)
	@echo
	@echo "[!] MAIN : All files compiled successfully"
	@echo

clean:
	@echo "#########################"
	@echo "# Cleaning Output files #"
	@echo "#########################"
	bash ./clean_all.sh

