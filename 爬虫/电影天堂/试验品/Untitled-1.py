import requests
from bs4 import BeautifulSoup
import re

dict = {}
name = []
link = 'http://www.dytt8.net/html/gndy/oumei/list_7_{}.html'
for n in range(1,190):
    l = link.format(n)
    
    res = requests.get(l)
    res.encoding = 'gb2312'
    soup = BeautifulSoup(res.text,'html.parser')


    for title in soup.select('.co_content8 table a'):
        name.append(title.text)

        

        url = 'http://www.dytt8.net' + title['href']
        res = requests.get(url)                               #解析单个电影网址
        res.encoding = 'gb2312'
        soup = BeautifulSoup(res.text,'html.parser')

        title = soup.select('.co_content8 td  a')             #获取迅雷链接


        for str  in name:
            print(name)
            dict[name] = title[0].text
       
        