import requests
from bs4 import BeautifulSoup
import time
import threading

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

def photo_xiazai(l,n):
    res = requests.get(l)
    soup = BeautifulSoup(res.text,'html.parser')

    for src in soup.select('.lazy'):
        photo_src = src['data-original']
        #print(src)
        photo_name = src['alt']
        #print(photo_name)
        #print(photo_src)

        name = photo_name.replace('?','-')              #替换name中非法字符
        name = photo_name.replace(':','-')
        r = requests.get(photo_src)
        str = name + '.jpg'
        with open(r'C:\Users\Administrator\Desktop\photos\\' + str, 'wb') as f:
            f.write(r.content)
    print('写入成功%d页'%n)
s = time.time()
link = 'http://www.mzitu.com/page/{}/'          #第二页开始的链接
for n in range(182)[1:]:                        #可以定期更新页码
    l = link.format(n)
    print('开始第%d页'%n)
    t = threading.Thread(target=photo_xiazai,args=(l,n))
    t.start()
t.join()
e = time.time()
print('多线程版,花费%.2fs'%(e-s)) 