import requests
from bs4 import BeautifulSoup
import os


  




headers = {'User-Agent':"Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36"
          ,'Referer':'http://www.mzitu.com/',}

url = 'http://www.mzitu.com/all/'

res = requests.get(url,headers = headers)   #获取页面
soup = BeautifulSoup(res.text,'html.parser')

for link in soup.select('.archives a'):
    url = link['href']                           #得到每个图的网页
    res = requests.get(url,headers = res.headers)    #  二轮解析 得到图片scr
    soup = BeautifulSoup(res.text,'html.parser')
    src = soup.select('.main-image img')
    name = src[0]['alt']                            #获得name
    src = src[0]['src']                             #获得图片地址

    name = name.replace('?','-')              #替换name中非法字符
    name = name.replace(':','-')
    name = name.replace(' ','-')
    print(name)

    r = requests.get(src,stream = True)
    str = name + '.jpg'
    with open(r'C:\Users\Administrator\Desktop\photos\\' + str, 'wb') as f:
        for chunk in r.iter_content(chunk_size=32):
            f.write(chunk)


    



        



 
 
