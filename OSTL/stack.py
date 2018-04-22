import array

class Stack:

	def __init__(self, max_length):
		self.top = -1
		self.max_length = max_length
		self.stack = array.array('f', list(-1 for x in range(max_length)))

	def pop(self):
		if self.top > 0:
			data = self.stack[self.top]
			self.top -= 1
			print("Popped %d from stack"%data);
		elif self.top == 0:
			data = self.stack[self.top]
			self.top = -1
			print("Stack is now Empty")
		elif self.top == -1:
			print("Stack Underflow")
			return -1
		return data

	def push(self, data):
		if self.top == -1:
			self.top = 0
			self.stack[self.top] = data
			print("Initialized Stack")
		elif self.top < self.max_length:
			self.top += 1
			self.stack[self.top] = data
			print("Pushed %d into stack"%data)
		else:
			print("Stack Overflow")


mystack = Stack(5)
print("> push 4")
mystack.push(4)
print("> push 5")
mystack.push(5)
print("> pop")
mystack.pop()
print("> push 6")
mystack.push(6)
print("> push 7")
mystack.push(7)
print("> pop")
mystack.pop()
print("> pop")
mystack.pop()
print("> pop")
mystack.pop()
print("> pop")
mystack.pop()
