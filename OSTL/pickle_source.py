from Employee import Employee
import pickle

f = open("employee.dat", 'wb')

n = int(input("No. of Employees > "))

for i in range(n):
	id = int(input("ID > "))
	name = input("Name > ")
	e = Employee(id, name)
	pickle.dump(e, f)

f.close()
