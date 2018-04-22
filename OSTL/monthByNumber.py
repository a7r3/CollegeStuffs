# Creating a dictionary of Months
# Key - Month name
# Value - The Month sequence number

# String containing three-lettered months, splitted by space
monthStr = "jan feb mar apr may jun jul aug sep oct nov dec"

# Breaking down the string into multiple strings (list), with the
# specified breaking point (delimiter they said)
monthList = monthStr.split(" ")

# Creating an Empty Dictionary
monthDict = {}

# Making the dictionary useful
for i in range(len(monthList)):
	# Creating key-value pair in monthDict
	# monthList[i] - Three lettered Month - Key
	# i + 1 - Month Sequence number - Value
	monthDict[monthList[i]] = i + 1

# DEBUG eet
# print(monthDict)

# Ask the user to enter a month
monthUser = input("Enter a month (spell properly pls)\n")

# Convert the month string provided by user
# 1. To lowercase
# 2. Get the string from index 0 to 2
monthUser = monthUser.lower()[0:3]

# Print the Month number
# Not put conditions for wrong three-lettered month, for now
print("Month Sequence > %d"%monthDict[monthUser])
