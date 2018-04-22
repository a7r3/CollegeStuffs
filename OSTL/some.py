from tkinter import *
from tkinter import ttk
from tkinter import messagebox

class form:

    def __init__(self, master):
        self.master = master
        master.title("Exam Form")

        self.name_label = Label(master, text="Name")
        vcmd = master.register(self.validate)
        self.name_entry = Entry(master, validate="key", validatecommand=(vcmd, '%i'))

        self.class_label = Label(master, text="Class")
        vcmd = master.register(self.validate) 
        self.class_entry = Entry(master, validate="key", validatecommand=(vcmd, '%i'))

        self.prn_label = Label(master, text="PRN")
        vcmd = master.register(self.validate) 
        self.prn_entry = Entry(master, validate="key", validatecommand=(vcmd, '%i'))

        self.sem_label = Label(master, text="Semester")
        vcmd = master.register(self.validate) 
        self.sem_entry = Entry(master, validate="key", validatecommand=(vcmd, '%i'))

        self.reg_label = Label(master, text="Regular/KT")
        vcmd = master.register(self.validate) 
        self.reg_entry = Entry(master, validate="key", validatecommand=(vcmd, '%i'))

        self.subject_label = Label(master, text="Subject")
        vcmd = master.register(self.validate) 
        self.subject_entry = Entry(master, validate="key", validatecommand=(vcmd, '%i'))

        self.th_label = Label(master, text="TH")
        vcmd = master.register(self.validate) 
        self.th_entry = Entry(master, validate="key", validatecommand=(vcmd, '%d'))

        self.tw_label = Label(master, text="TW")
        vcmd = master.register(self.validate) 
        self.tw_entry = Entry(master, validate="key", validatecommand=(vcmd, '%d'))

        self.ia_label = Label(master, text="IA")
        vcmd = master.register(self.validate) 
        self.ia_entry = Entry(master, validate="key", validatecommand=(vcmd, '%d'))

        self.or_label = Label(master, text="OR")
        vcmd = master.register(self.validate) 
        self.or_entry = Entry(master, validate="key", validatecommand=(vcmd, '%d'))

        self.pr_label = Label(master, text="PR")
        vcmd = master.register(self.validate) 
        self.pr_entry = Entry(master, validate="key", validatecommand=(vcmd, '%d'))

        self.submit_button = Button(master, text="Submit Form", command=self.submit)
    
        self.name_label.grid(row=0, column=0, sticky=W)				
        self.name_entry.grid(row=1, column=0, columnspan=6, sticky=W+E)
        self.class_label.grid(row=2, column=0, sticky=W)				
        self.class_entry.grid(row=3, column=0, columnspan=3, sticky=W+E)
        self.prn_label.grid(row=2, column=3, sticky=W)				
        self.prn_entry.grid(row=3, column=3, columnspan=1, sticky=W+E)
        self.sem_label.grid(row=4, column=0, sticky=W)				
        self.sem_entry.grid(row=5, column=0, columnspan=3, sticky=W+E)
        self.reg_label.grid(row=4, column=3, sticky=W)				
        self.reg_entry.grid(row=5, column=3, columnspan=3, sticky=W+E)
        self.subject_label.grid(row=6, column=0, sticky=W)				
        self.th_label.grid(row=6, column=5, sticky=W)				
        self.tw_label.grid(row=6, column=6, sticky=W)				
        self.ia_label.grid(row=6, column=7, sticky=W)				
        self.or_label.grid(row=6, column=8, sticky=W)				
        self.pr_label.grid(row=6, column=9, sticky=W)				

        course_values = list()

        for i in range(7, 13):
            val_tuple = (StringVar(), IntVar(), IntVar(), IntVar(), IntVar(), IntVar())
            course_values.append(val_tuple)
            Entry(master, textvariable=course_values[i-7][0]).grid(row=i, column=0, columnspan=5, sticky=W+E)
            Checkbutton(master, variable=course_values[i-7][1]).grid(row=i, column=5)
            Checkbutton(master, variable=course_values[i-7][2]).grid(row=i, column=6)
            Checkbutton(master, variable=course_values[i-7][3]).grid(row=i, column=7)
            Checkbutton(master, variable=course_values[i-7][4]).grid(row=i, column=8)
            Checkbutton(master, variable=course_values[i-7][5]).grid(row=i, column=9)

        self.submit_button.grid(row=13, column=2, columnspan=5)

    def submit(self):
        messagebox.showinfo(title="Success", message="Form has been submitted successfully")
        pass

root = Tk()
gui = form(root)
root.mainloop()