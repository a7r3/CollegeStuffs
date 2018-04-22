# Creating a List
# Datatype Mashup
yetAnotherList = ["This", 12, "was", 90.33, "a", True, "List"]

# list_name[START:END:STEP_SIZE]
# Default values - 0, len(list_name), 1
yetAnotherList[::3]

# Start from End of List
# Step size -1 indicates that we are taking a step backward
yetAnotherList[-1::-1] #ThugLyf

# Reversing a list
reversify = yetAnotherList[-1::-1] #ThugLyf

# Lists are mutable
yetAnotherList[5] = 420

# Appending an element to the list
list.append("with")

# Lists can be extended - with another list
list.extend(["extended", "version"])

# Deleting an element from a list
del(yetAnotherList4])

# Deleting a range of elements
del(yetAnotherList[2:4])

# Returns a range object, and list() call over it converts it to a list
fooList = list(range(0,50))
print(fooList)
