import requests
import re
from bs4 import BeautifulSoup
from tkinter import *
#初始化Tk
top = Tk()
top.title('电影天堂电影磁力链接获取器')
top.geometry('400x300+300+100')



list= []
dict = {} 
link = 'http://www.dytt8.net/html/gndy/oumei/list_7_2.html'

    
res = requests.get(link)    
res.encoding = 'gb2312'
soup = BeautifulSoup(res.text,'html.parser')

 
for title in soup.select('.co_content8 table b a'):    #将网站及迅雷链接放入dict中
    name= title.text
    url = 'http://www.dytt8.net' + title['href']          #获取网址
    list.append(name)

    res = requests.get(url)                               #解析单个电影网址
    res.encoding = 'gb2312'
    soup = BeautifulSoup(res.text,'html.parser')

    title = soup.select('.co_content8 td  a')             #获取迅雷链接
    title = title[0].text
    dict[name] = title
    
                       





def printList(event):
    print lb.get(lb.curselection()) 
ls = Listbox(top)
ls.bind('<Double-Button-1>',printList)
for i in range(10):
    lb.insert(END,str(i*100))
lb.pack()

    
    



top.mainloop()      #进入消息循环