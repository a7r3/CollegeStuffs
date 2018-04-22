import pickle
from Employee import Employee

f = open("employee.dat", 'rb')

print("Employee Details\n")

for i in range(2):
	e = pickle.load(f)
	e.display()

f.close()
