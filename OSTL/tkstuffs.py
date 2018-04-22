import sqlite3

db = sqlite3.connect("Student.db")
cursor = db.cursor()
cursor.execute("CREATE TABLE IF NOT EXISTS STUDENT (id INTEGER PRIMARY KEY, name TEXT, course TEXT);")
print("Table Created Successfully")

class Student:
	def __init__(self, id, name, course):
		self.id = id
		self.name = name
		self.course = course

	def gettuple(self):
		return (self.id, self.name, self.course)

def insertrow(student):
	insert_query = "INSERT INTO STUDENT (id, name, course) VALUES(?, ?, ?)"
	cursor.execute(insert_query, (student.id, student.name, student.course))
	print("\nInserted Student record %d successfully"%student.id)

def deleterow(data_id):
	delete_query = "DELETE FROM STUDENT WHERE id= ?"
	cursor.execute(delete_query, (data_id,))
	print("\nDeleted Student record %d successfully"%data_id)

def updaterow(student):
	update_query = "UPDATE STUDENT SET name= ?, course= ? WHERE id= ?"
	cursor.execute(update_query, (student.name, student.course, student.id))
	print("\nUpdate Student record %d successfully"%student.id)
def display():
	print("\nTable Snapshot\n")
	data = cursor.execute("SELECT * FROM STUDENT")
	for d in data.fetchall():
		print(d[0], d[1], d[2])

insertrow(Student(0, 'Johnson', 'PPT'))
display()
insertrow(Student(1, 'Delta', 'ME'))
display()
insertrow(Student(2, 'Arvind', 'CE'))
display()
insertrow(Student(3, 'Foobar', 'IT'))
display()
deleterow(1)
display()
# Updating the 0th Student's Info
# Changing the Branch
updaterow(Student(0, 'Johnson', 'CE'))
display()
db.commit()
