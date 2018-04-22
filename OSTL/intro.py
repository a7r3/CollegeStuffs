str = "PyBoi"

integ = 1

flooat = 3.14576

complax = 1+3j

# Boolyian - True/False (T and F capital)
isAlive = True

print(str, " -> ", type(str),
 "\n", integ, " -> ", type(integ),
 "\n", flooat, " -> ", type(flooat),
 "\n", complax, " -> ", type(complax),
 "\n", "isAlive -> ", isAlive, " -> ", type(isAlive))

# For a complex no
# real -> retrieve real part
# imag -> retrieve imaginary part
print("Real -> ", complax.real, "\n", "Imaginary -> ", complax.imag)

# ! -> not ;-;
isDed = not isAlive
print(isDed)

foo, bar = True, False
print("foo && bar = ", foo and bar)
print("foo || bar = ", foo or bar)

# One line assignment
u,v = 1,2
print(u, "\n", v)

# Format specifiers
a = 2.4432345989085

# Prints 4 places
print("%.4f"%a)
print("%f"%a)

# Combining arguments - %(arg1, arg2, ...)
print("%.1f | %.1fj"%(complax.real, complax.imag))

# Strings
str1 = "noob"
str2 = "life"

# concat
print(str1+str2)

x = 123
# Getting other base equivalents
print("bin -> ", bin(x), "\nHex ->", hex(x), "\nOct ->", oct(x))
# Type is string :D
print(type(bin(x)))

# Operators
# + / * - %
# exponential is ** here
# ^ is XOR operator
f = 2
b = 3
print("Add -> ", f+b, "\nSub -> ",  f-b, "\nMul -> ",  f*b, "\nDiv -> ", f%b, "\nExp -> ", f**b)

n = 2.2342342554 // 1.2134523452
print("Integer -> ", n)
# // gets the integer part from a division

# input and raw_input
# For Py2.7
# input - Takes user input as a String
# raw_input - Takes user input as any datatype

# Py3 - Only input()
s = input("Enter something\n> ")
print(s)
cel = int(input("Enter temperature in Celsius\n\n> "))

fah = (1.8 * cel) + 32.0

print("\nCelsius = %f"%cel)
print("\nFahrenheit Equivalent = %f"%fah, "\n")

# Every String is converted into an array
strr = "   IWantPeace"

# Here's how it works
print(strr[0])

# Strings are Immutable
# Don't do this
# strr[0] = "A"

# Check if strr starts with some string
print(strr.startswith("hell"))
print(strr.endswith("Peace"))
print(strr)
print(strr.upper())
print(strr.lower())
print(len(strr))
print(strr.index("Want"))
print(strr.strip())

# Remove leading/trailing character
# Gib character, and it'd strip off that character
print(strr.strip("    I"))

# Replace
print(strr.replace("Peace", "Death"))
star = "O  hai there"
splitt = star.split("t")
print(splitt)

# join()
# joins the elements of a list
# It has to be called with the string, which joins these elements
print("--".join(splitt))

# Nu hallo pls
print("Hello", end="\r")
print("Py Py Py")
