class Point:
        x = None
        w = None

        def __init__(self, x):
                self.x = x
                self.w = -1

points = [
    # Age, Income, Student, Credits, Bhai or not
    Point(['<=30' ,'hig','n','f','n']),
    Point(['<=30' ,'hig','n','e','n']),
    Point(['31-40','hig','n','f','y']),
    Point(['>40'  ,'med','n','f','y']),
    Point(['>40'  ,'low','y','f','y']),
    Point(['>40'  ,'low','y','e','n']),
    Point(['31-40','low','y','e','y']),
    Point(['<=30' ,'med','n','f','n']),
    Point(['<=30' ,'low','y','f','y']),
    Point(['>40'  ,'med','y','f','y']),
    Point(['<=30' ,'med','y','e','y']),
    Point(['31-40','med','n','e','y']),
    Point(['31-40','hig','y','f','y']),
    Point(['>40'  ,'med','n','e','n']),
]

w = [1, 2, 1, 2]

point = Point(['<=30', 'med', 'y', 'f', 'kek'])

for p in points:
	p.w = 0
	for i in range(len(point.x)):
		if i == len(point.x) - 1:
			continue
		j = 0
		if p.x[i] == point.x[i]:
			j = 1
		p.w = p.w + (w[i] * j)

points.sort(key = lambda p : p.w, reverse = True)

for point in points[0:5]:
        if point.x[-1] not in label:
                label[point.x[-1]] = 1
        else:
                label[point.x[-1]] = label[point.x[-1]] + 1

point.x[-1] = max(label.items(), key=operator.itemgetter(1))

print("Result : " + point.x[-1])
