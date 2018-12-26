
#修改版

import requests
import re
from bs4 import BeautifulSoup
from tkinter import *







#欧美
def a():
    l= []
    dict = {}
    link = 'http://www.dytt8.net/html/gndy/oumei/list_7_{}.html'
    for n in range(1,190):
        l = link.format(n)
    
        res = requests.get(l)
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')

 
        for title in soup.select('.co_content8 table b a'):    #将网站及迅雷链接放入dict中
            name= title.text                                      #获取名字
            url = 'http://www.dytt8.net' + title['href']          #获取网址
                
            res = requests.get(url)                               #解析单个电影网址
            res.encoding = 'gb2312'
            soup = BeautifulSoup(res.text,'html.parser')

            title = soup.select('.co_content8 td  a')             #获取迅雷链接
            title = title[0].text
            if re.match(r'[*]',name):
                pass
            else:
                dict[name] = title
                var.set(name)                                #将名字对应迅雷链接放入dict
                
                Label(top,textvariable = var).pack()


#日韩
def c():
    l= []
    dict = {}
    link = 'http://www.ygdy8.net/html/gndy/rihan/list_6_{}.html'
    for n in range(1,33):
        l = link.format(n)
    
        res = requests.get(l)
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')

 
        for title in soup.select('.co_content8 table b a'):    #将网站及迅雷链接放入dict中
            name= title.text                                      #获取名字
            url = 'http://www.dytt8.net' + title['href']          #获取网址
                
            res = requests.get(url)                               #解析单个电影网址
            res.encoding = 'gb2312'
            soup = BeautifulSoup(res.text,'html.parser')

            title = soup.select('.co_content8 td  a')             #获取迅雷链接
            title = title[0].text
            if re.match(r'[*]',name):
                pass
            else:
                dict[name] = title                                #将名字对应迅雷链接放入dict
            print(dict)


#华语
def b():
    l= []
    dict = {}
    link = 'http://www.ygdy8.net/html/gndy/china/list_4_{}}.html'
    for n in range(1,103):
        l = link.format(n)
    
        res = requests.get(l)
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')

 
        for title in soup.select('.co_content8 table b a'):    #将网站及迅雷链接放入dict中
            name= title.text                                      #获取名字
            url = 'http://www.dytt8.net' + title['href']          #获取网址
                
            res = requests.get(url)                               #解析单个电影网址
            res.encoding = 'gb2312'
            soup = BeautifulSoup(res.text,'html.parser')

            title = soup.select('.co_content8 td  a')             #获取迅雷链接
            title = title[0].text
            if re.match(r'[*]',name):
                pass
            else:
                dict[name] = title                                #将名字对应迅雷链接放入dict
            print(dict)



#创建3个按键


























#搜索

def find():
    str = input()    #输入str
    dict.get('^[*?str字$')

    



    