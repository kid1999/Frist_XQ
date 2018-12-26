
import requests
import re
from bs4 import BeautifulSoup
from tkinter import *


#主体
top = Tk()
top.title('电影天堂电影磁力链接获取器')
top.geometry('400x300+300+100')





#欧美

   
dict1 = {}
list1 = []
link = 'http://www.dytt8.net/html/gndy/oumei/list_7_{}.html'
for n in range(1,190):
    l = link.format(n)
    
    res = requests.get(l)
    res.encoding = 'gb2312'
        
    soup = BeautifulSoup(res.text,'html.parser')

 
    for title in soup.select('.co_content8 table b a'):    #将网站及迅雷链接放入dict中
        name= title.text                                      #获取名字
        url = 'http://www.dytt8.net' + title['href']          #获取网址

        list1.append(name)
                
        res = requests.get(url)                               #解析单个电影网址
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')

        title = soup.select('.co_content8 td  a')             #获取迅雷链接
        title = title[0].text
        if re.match(r'[*]',name):
            pass
        else:
            dict1[name] = title
                

#日韩

dict2 = {}
list2 = []
link = 'http://www.ygdy8.net/html/gndy/rihan/list_6_{}.html'
for n in range(1,33):
    l = link.format(n)
    
    res = requests.get(l)
    res.encoding = 'gb2312'
    soup = BeautifulSoup(res.text,'html.parser')

 
    for title in soup.select('.co_content8 table b a'):    #将网站及迅雷链接放入dict中
        name= title.text                                      #获取名字
        url = 'http://www.dytt8.net' + title['href']          #获取网址

        list2.append(name)
                
        res = requests.get(url)                               #解析单个电影网址
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')

        title = soup.select('.co_content8 td  a')             #获取迅雷链接
        title = title[0].text
        if re.match(r'[*]',name):
            pass
        else:
            dict2[name] = title                                #将名字对应迅雷链接放入dict
                


#华语

dict3 = {}
list3 =[]
link = 'http://www.ygdy8.net/html/gndy/china/list_4_{}}.html'
for n in range(1,103):
    l = link.format(n)
    
    res = requests.get(l)
    res.encoding = 'gb2312'
    soup = BeautifulSoup(res.text,'html.parser')

 
    for title in soup.select('.co_content8 table b a'):    #将网站及迅雷链接放入dict中
        name= title.text                                      #获取名字
        url = 'http://www.dytt8.net' + title['href']          #获取网址

        list3.append(name)
                
        res = requests.get(url)                               #解析单个电影网址
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')

        title = soup.select('.co_content8 td  a')             #获取迅雷链接
        title = title[0].text
        if re.match(r'[*]',name):
            pass
        else:
            dict3[name] = title                                #将名字对应迅雷链接放入dict
            
top=Tk()
top.title("菜单")
top.geometry("400x300+300+100")

# 创建一个菜单项，类似于导航栏
menubar=Menu(top)

# 创建菜单项
fmenu1=Menu(top)
for name in list1:
    # 如果该菜单时顶层菜单的一个菜单项，则它添加的是下拉菜单的菜单项。
    fmenu1.add_command(label=name)

fmenu2=Menu(top)
for item in list2:
    fmenu2.add_command(label=item)

fmenu3=Menu(top)
for item in list3:
    fmenu3.add_command(label=item)

fmenu4=Menu(top)
for item in ["版权信息","其他说明"]:
    fmenu4.add_command(label=item)

# add_cascade 的一个很重要的属性就是 menu 属性，它指明了要把那个菜单级联到该菜单项上，
# 当然，还必不可少的就是 label 属性，用于指定该菜单项的名称
menubar.add_cascade(label="欧美电影",menu=fmenu1)
menubar.add_cascade(label="日韩电影",menu=fmenu2)
menubar.add_cascade(label="国产电影",menu=fmenu3)
menubar.add_cascade(label="关于",menu=fmenu4)

# 最后可以用窗口的 menu 属性指定我们使用哪一个作为它的顶层菜单
top['menu']=menubar
top.mainloop()
