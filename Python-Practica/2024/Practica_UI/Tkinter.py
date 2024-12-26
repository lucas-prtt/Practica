import tkinter as tk
from tkinter import ttk

def quitProgram():
    a = entry_stringVal.get()
    print(a)

    if a == "ByeWorld":
        root.destroy()


root = tk.Tk()
frame = ttk.Frame(root, padding = 90)
frame.grid()

label = ttk.Label(frame, text = "HelloWorld")
label.grid(column = 0, row = 0)


entry_stringVal = tk.StringVar(value = "Test")
entry = ttk.Entry(frame, textvariable=entry_stringVal)
entry.grid(column=2, row = 3)
 

button = ttk.Button(frame, text = "Quit", command = lambda: quitProgram()).grid(column = 1, row = 0)

    
root.mainloop()
