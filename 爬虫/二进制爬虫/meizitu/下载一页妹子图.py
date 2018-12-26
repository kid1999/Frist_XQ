import requests
from bs4 import BeautifulSoup

#第一页的

res = requests.get('http://www.mzitu.com/')
soup = BeautifulSoup(res.text,'html.parser')

for src in soup.select('.lazy'):
    photo_src = src['data-original']
    #print(src)
    photo_name = src['alt']
    print(photo_name)
    print(photo_src)

    name = photo_name.replace('?','-')              #替换name中非法字符
    name = photo_name.replace(':','-')
    r = requests.get(photo_src)
    str = name + '.jpg'
    with open(r'C:\Users\Administrator\Desktop\photos\\' + str, 'wb') as f:
        f.write(r.content) 
