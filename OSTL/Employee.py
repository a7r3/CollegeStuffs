class Employee:

	def __init__(self, id, name):
		self.id = id
		self.name = name

	def display(self):
		print("ID : %d"%self.id)
		print("Name : %s"%self.name)
