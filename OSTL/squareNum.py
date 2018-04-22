# Get the string of numbers, seperated by space
numberInput = input("Enter the numbers (space-seperated)\n")

# Break down the string with the specified breakpoint (delimiter they say)
numberList = numberInput.split(" ")

print("\nProvided Numbers\n")
print(numberList)

for i in range(len(list)):
	# Since the numbers are in str format, convert them to string first
	# so that the exponent operation stands valid
	numberList[i] = int(numberList[i])**2

print("\nSquared Numbers\n")
print(numberList)
