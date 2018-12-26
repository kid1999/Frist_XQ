import requests
from bs4 import BeautifulSoup

headers ={
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
            'Accept-Encoding': 'gzip, deflate',
            'Accept-Language': 'zh-CN,zh;q=0.9',
            'Cache-Control': 'max-age=0',
            'Connection': 'keep-alive',
            
            
            'If-Modified-Since': 'Sun, 29 Apr 2018 13:23:46 GMT',
            'Referer': 'http://www.mzitu.com/',
            'Upgrade-Insecure-Requests': '1',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36',
}



url = 'http://www.mzitu.com/132145/4'

                           
res = requests.get(url,headers = headers )    #  得到图片scr

soup = BeautifulSoup(res.text,'html.parser')
src = soup.select('.main-image img')
name = src[0]['alt']                            #获得name
src = src[0]['src'] 
#print(src)

name = name.replace('?','-')              #替换name中非法字符
name = name.replace(':','-')
print(name)
r = requests.get(src)
str = name + '.jpg'
with open(r'C:\Users\Administrator\Desktop\photos\\' + str, 'wb') as f:
    f.write(r.content) 