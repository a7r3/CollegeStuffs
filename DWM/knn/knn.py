import operator

class Point:
	x = None
	y = None
	d = None
	q = None

	def __init__(self, x, y, d, q):
		self.x = x
		self.y = y
		self.d = d
		self.q = q

	
points = list()

num = int(input("Enter number of points > "))

num_neighbors = int(input("Enter number of neighbors > "))

label = {}

for i in range(num):
	# Get the points
	print("")
	x = int(input("Enter X" + str(i+1) + " > "))
	y = int(input("Enter Y" + str(i+1) + " > "))
	q = input("Enter Label > ")
	points.append(Point(x, y, -1, q))

print("\nEnter new point to be classified")
x = int(input("Enter X value > "))
y = int(input("Enter Y value > "))
new_point = Point(x, y, -1, None)

for point in points:
	point.d = pow(abs(point.x - new_point.x), 2) + pow(abs(point.y - new_point.y), 2)

points.sort(key = lambda p : p.d, reverse = False)

for point in points[0:num_neighbors]:
	if point.q not in label:
		label[point.q] = 1
	else:
		label[point.q] = label[point.q] + 1

print("\nNew Point (" + str(new_point.x) + ", " + str(new_point.y) + ") is classfied as \'" + max(label.items(), key=operator.itemgetter(1))[0] + "\'")
