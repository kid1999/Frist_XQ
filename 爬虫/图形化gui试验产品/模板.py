from tkinter import *

root = Tk()

root.title("TkinterSimple")
#窗口大小
width ,height= 600, 600
#窗口居中显示
root.geometry('%dx%d+%d+%d' % (width,height,(root.winfo_screenwidth() - width ) / 2, (root.winfo_screenheight() - height) / 2))
#窗口最大值
root.maxsize(600,600)
#窗口最小值
root.minsize(600,600)

def prints():
    print("button")

button = Button(root, text="Button", command=prints)
button.pack()

label = Label(root, text="Label")
label.pack()

entry = Entry(root)
entry.pack()

checkbutton = Checkbutton(root, text="CheckButton")
checkbutton.pack()

radioButton = Radiobutton(root, text="RadioButton")
radioButton.pack()

root.mainloop()