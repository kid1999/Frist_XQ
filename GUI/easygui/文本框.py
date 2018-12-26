
import easygui as g
import os

#打开一个txt文件

# msg='文件【record.txt】的内容如下：'
# title='显示文件内容'
# file_path=g.fileopenbox()#   默认参数  default='*.txt'
# with open(file_path) as f:
#     #title=os.path.basename(file_path)
#     text=f.read()
#     g.textbox(msg,title,text)


#调用文件选择框
path = g.fileopenbox()
print(path)