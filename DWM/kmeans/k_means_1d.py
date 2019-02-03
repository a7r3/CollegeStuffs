numbers = list(map(int, input("Enter the numbers > ").split(" ")))

numbers.sort()

cluster_centers = {}

for x in numbers:
	cluster_centers[x] = -1

print(numbers)

cluster_count = int(input("Enter the number of clusters > "))

clusters = {}

for i in range(cluster_count):
	center = int(input("Cluster Center " + str(i + 1) + " > "))
	clusters[center] = list()

cluster_centers_maintained = False

while not cluster_centers_maintained:
	for x in numbers:
		min = -1
		min_center = cluster_centers[x]
		for y in clusters.keys():
			if min == -1 or abs(x - y) < min:
				min = abs(x - y)
				min_center = y

		if min != 0 and x not in clusters[min_center]:
			clusters[min_center].append(x)
			if cluster_centers[x] != -1:
				clusters[cluster_centers[x]].remove(x)
			cluster_centers[x] = min_center

	cluster_centers_maintained = True

	print(clusters)

	for center, elements in clusters.items():

		if len(elements) == 0:
			mean = center
		else:
			mean = int(sum(elements) / len(elements))
		if mean != center:
			cluster_centers_maintained = False
			clusters[mean] = clusters.pop(center)
			clusters[mean].remove(mean)