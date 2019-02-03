class Cluster:
	x = None
	y = None

	def __init__(x,y):
		self.x = x
		self.y = y

count = int(input("Enter the number of points >"))

numbers = []

for i in range(count):
	numbers.append(
		Cluster(
			int(input("Cluster Center X" + str(i + 1) + " > ")),
			int(input("Cluster Center Y" + str(i + 1) + " > "))
		)
	)

cluster_centers = dict()

for x in numbers:
	cluster_centers[x] = Cluster(-1, -1)

print(numbers)

cluster_count = int(input("Enter the number of clusters > "))

clusters = {}

for i in range(cluster_count):
	center = Cluster(
			int(input("Cluster Center X" + str(i + 1) + " > ")),
			int(input("Cluster Center Y" + str(i+1) + " > "))
			)
	clusters[center] = list()

cluster_centers_maintained = False

while not cluster_centers_maintained:
	for x in numbers:
		min = -1
		min_center = cluster_centers[x]
		for y in clusters.keys():
			mag = pow(abs(x.x - y.x), 2) + pow(abs(x.y - y.y), 2)
			if min == -1 or mag < min:
				min = mag
				min_center = y

		if min != 0 and x not in clusters[min_center]:
			clusters[min_center].append(x)
			if cluster_centers[x] != Cluster(-1, -1):
				clusters[cluster_centers[x]].remove(x)
			cluster_centers[x] = min_center

	cluster_centers_maintained = True

	print(clusters)

	for center, elements in clusters.items():

		totalX = 0
		totalY = 0

		for x in elements:
			totalX = totalX + x.x
			totalY = totalY + x.y

		if len(elements) == 0:
			mean = center
		else:
			mean = Cluster(int(totalX / len(elements)), int(totalY / len(elements)))
			cluster_centers_maintained = False
			clusters[mean] = clusters.pop(center)
			clusters[mean].remove(mean)