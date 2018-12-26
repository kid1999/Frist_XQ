from tkinter import *
import tkinter.filedialog

root = Tk()

def xz():
    filename = tkinter.filedialog.askopenfilename()
    if filename != '':
        lb.config(text = "您选择的文件是："+filename)
    else:
        lb.config(text = "您没有选择任何文件")

lb = Label(root,text = '')
lb.pack()
btn = Button(root,text="弹出选择文件对话框",command=xz)
btn.pack()
root.mainloop()