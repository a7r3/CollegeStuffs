# Number of elements to be printed from Fibo series
n = int(input("Enter the number of elements > "))

# The List, which would hold the Fibonacci numbers
# upto the specified count
fibList = [0, 1]

a = 0
b = 1

# Starting from 2, since we've started off with 2 numbers
for i in range(2, n):
	# Simultaneous assignment
	a, b = b, a+b
	fibList.append(b)

print("\nFibonacci Series upto %d\n"%n)
print(fibList)

