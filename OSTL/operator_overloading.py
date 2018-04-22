# Operator Overloading

class Fraction:

	def __init__(self, a, b):
		self.__a = a
		self.__b = b

	def geta(self): return self.__a

	def seta(self, a): self.__a = a

	def getb(self): return self.__b

	def setb(self): self.__b = b

	def __add__(self, f):
		result = Fraction(((self.__a * f.__b) + (f.__a * self.__b)), (self.__b * f.__b))
		return result

	def __mul__(self, f):
		result = Fraction((self.__a * f.__a), (self.__b * f.__b))
		return result

	def __sub__(self, f):
		result = Fraction(((self.__a * f.__b) - (f.__a * self.__b)), (self.__b * f.__b))
		return result

f1 = Fraction(1, 2)

f2 = Fraction(5, 2)

f3 = f1 + f2

f4 = f1 - f2

f5 = f1 * f2

print("Add -> %d/%d"%(f3.geta(), f3.getb()))
print("Sub -> %d/%d"%(f4.geta(), f4.getb()))
print("Mul -> %d/%d"%(f5.geta(), f5.getb()))
