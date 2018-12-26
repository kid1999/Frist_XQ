
#修改版

import requests
from bs4 import BeautifulSoup


#欧美
def a():
    l= []
    link = 'http://www.dytt8.net/html/gndy/oumei/list_7_{}.html'
    for n in range(1,190):
        l = link.format(n)
    
        res = requests.get(l)
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')


        for title in soup.select('.co_content8 table a'):
            a = title.text
            b = 'http://www.dytt8.net' + title['href']
            print(a)
    
#华语
def b():
    l= []
    link = 'http://www.ygdy8.net/html/gndy/china/list_4_{}}.html'
    for n in range(1,103):
        l = link.format(n)
    
        res = requests.get(l)
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')


        for title in soup.select('.co_content8 table a'):
            a = title.text
            b = 'http://www.dytt8.net' + title['href']
            print(a)

#日韩
def c():
    l= []
    link = 'http://www.ygdy8.net/html/gndy/rihan/list_6_{}.html'
    for n in range(1,33):
        l = link.format(n)
    
        res = requests.get(l)
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')


        for title in soup.select('.co_content8 table a'):
            a = title.text
            b = 'http://www.dytt8.net' + title['href']
            print(a)


res = requests.get(b)
res.encoding = 'gb2312'
soup = BeautifulSoup(res.text,'html.parser')

title = soup.select('.co_content8 td  a')
title = title[0].text
print(title)