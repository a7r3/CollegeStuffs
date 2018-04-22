with open("file", 'r') as f1:
	with open("file1", 'r') as f2:
		first_lines = f1.readlines()
		second_lines = f2.readlines()
		for i in range(len(first_lines)):
			first_lines[i] = first_lines[i].strip("\n")
		for i in range(len(second_lines)):
			second_lines[i] = second_lines[i].strip("\n")
		common = set(first_lines) & set(second_lines)
		print("Common Lines : \n")
		for line in common: print(line)
