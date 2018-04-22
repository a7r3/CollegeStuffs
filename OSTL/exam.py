from tkinter import *

root = Tk()

name_label = Label(root, text="Name")
name_label.grid(row = 0, column = 0, padx=8, pady=8)
name_entry = Entry(root)
name_entry.grid(row = 0, column = 1, padx=8, pady=8)

semester_label = Label(root, text="Sem")
semester_label.grid(row = 0, column = 2, padx=8, pady=8)
semester_entry = Entry(root)
semester_entry.grid(row = 0, column = 3, padx=8, pady=8)

void_label = Label(root, text = "     ")
void_label.grid(row = 1, column = 2, padx = 8, pady = 8)

exam_type_label = Label(root, text="Regular/KT")
exam_type_label.grid(row = 1, column = 3, padx = 8, pady = 8)
exam_type_entry = Entry(root)
exam_type_entry.grid(row = 1, column = 4, padx = 8, pady = 8)

roll_label = Label(root, text="PRN")
roll_label.grid(row = 2, column = 0, padx=8, pady=8)
roll_entry = Entry(root)
roll_entry.grid(row = 2, column = 1, padx=8, pady=8)

void_label.grid(row = 1, column = 2, padx = 8, pady = 8)

branch_label = Label(root, text="Branch")
branch_label.grid(row = 2, column = 3, padx=8, pady=8)
branch_entry = Entry(root)
branch_entry.grid(row = 2, column = 4, padx=8, pady=8)

mobile_label = Label(root, text="Mobile no.")
mobile_label.grid(row = 3, column = 0, padx=8, pady=8)
mobile_entry = Entry(root)
mobile_entry.grid(row = 3, column = 1, padx=8, pady=8)

# Course Selection

courses_values = list()

# for i in range(6):
top = Toplevel()

val_tuple = (StringVar(), IntVar(), IntVar(), IntVar(), IntVar(), IntVar())
courses_values.append(val_tuple)
course_name = Entry(root, textvariable = courses_values[0][0])
# th tw ia or pr
course_th = Checkbutton(top, variable = courses_values[0][1], onvalue = 1, offvalue = 0)
course_tw = Checkbutton(top, variable = courses_values[0][2], onvalue = 1, offvalue = 0)
course_ia = Checkbutton(top, variable = courses_values[0][3], onvalue = 1, offvalue = 0)
course_or = Checkbutton(top, variable = courses_values[0][4], onvalue = 1, offvalue = 0)
course_pr = Checkbutton(top, variable = courses_values[0][5], onvalue = 1, offvalue = 0)

course_name.grid(top, row=0, column=0, padx = 8, pady = 8)
course_th.grid(top, row=0, column=1, padx = 8, pady = 8)
course_tw.grid(top, row=0, column=2, padx = 8, pady = 8)
course_ia.grid(top, row=0, column=3, padx = 8, pady = 8)
course_or.grid(top, row=0, column=4, padx = 8, pady = 8)
course_pr.grid(top, row=0, column=5, padx = 8, pady = 8)

def on_submit():
    print("Form Submitted re")

submit_button = Button(root, text = "Submit", command = on_submit)
submit_button.grid(row = 4, column = 2, padx = 8, pady = 8)

root.mainloop()
