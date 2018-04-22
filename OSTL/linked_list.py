class Node:

	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:

	def __init__(self, data):
		self.head = Node(data)

	def add_node_end(self, data):
		inter = self.head
		while inter.next != None:
			inter = inter.next
		new_node = Node(data)
		inter.next = new_node
		print("Added Node %d at End"%data)

	def add_node_start(self, data):
		new_node = Node(data)
		new_node.next = self.head
		self.head = new_node
		print("Added Node %d at Start"%data)

	def add_node_pos(self, data, pos):
		inter = self.head
		prev = inter
		i = pos
		while i != 0 or inter.next != None:
			prev = inter
			inter = inter.next
			i -= 1
		if i == 0:
			new_node = Node(data)
			new_node.next = inter
			prev.next = new_node
			print("Added Node %d at Position %d"%(data, pos))

	def display(self):
		print("Linked List Data:\n")
		inter = self.head
		print(inter.data)
		while inter.next != None:
			inter = inter.next
			print(inter.data)

	def getlen(self):
		i = 1
		inter = self.head
		while inter.next != None:
			i += 1
			inter = inter.next
		print("Length of LL is %d"%i)

	def find_node(self, data):
		inter = self.head
		if self.head.data == data:
			print("Data Found at 0th Position")
			return
		i = 1
		while inter.next != None:
			inter = inter.next
			if inter.data == data:
				print("Data Found at Position %d"%data)
				return

	def remove_node(self, data):
		inter = self.head
		prev = inter
		if inter.data == data:
			self.head = inter.next
			return
		while inter.data != data:
			prev = inter
			inter = inter.next
			if inter.data == data:
				print("Removed data %d from Linked List"%data)
				prev.next = inter.next
				inter = None
				return
			if inter.next == None:
				print("Data %d not found"%data)
				break

ll = LinkedList(4)

ll.add_node_start(3)
ll.add_node_end(5)
ll.add_node_start(2)
ll.add_node_end(6)
ll.add_node_pos(7, 4)
ll.remove_node(3)
ll.find_node(6)
ll.display()
ll.getlen()
