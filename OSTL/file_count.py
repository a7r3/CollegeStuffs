with open("file", 'r') as f:
	contents = f.read()
	print(contents)

	f.seek(50)
	print(f.read())

	f.seek(0,0)
	line_count = 0
	char_count = 0
	word_count = 0

	for linew in f:
		line_count += 1
		char_count += len(linew)
		word_count += len(linew.split())

	print("Line Count : %d\nChar Count : %d\nWord Count : %d"%(line_count, char_count, word_count))
