import os

for dirpath, dirname, filenames in os.walk("/home/arvind/Desktop/CollegeStuffs/OSTL"):
	for file in filenames:
		print(file)
