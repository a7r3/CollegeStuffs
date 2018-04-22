class Queue:

	def __init__(self, length):
		self.q = list()
		self.length = length
		self.front = -1
		self.rear = -1

	def insert(self, data):
		if self.rear == -1 and self.front == -1:
			self.q.append(data)
			self.rear = 0
			self.front = 0
			print("Queue Init")
		elif self.rear < self.length:
			self.q.append(data)
			self.rear += 1
			print("Inserted %d"%data)
		else:
			print("Queue Full")

	def delete(self):
		if self.front < self.rear:
			self.front += 1
			return self.q.pop()
		else:
			print("Queue Empty")

	def print(self):
		print(self.front, self.rear)
		for i in range(self.front, self.rear):
			print(self.q[i], "| ")


q = Queue(5)
q.insert(10)
q.insert(20)
q.insert(30)
q.insert(40)
q.delete()
q.delete()
q.print()
