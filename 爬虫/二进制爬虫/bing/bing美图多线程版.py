import requests
from bs4 import BeautifulSoup
import threading
import time

                                      #调用多线程下载 快一倍
def bing(link,n):
    header = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36'}

    res = requests.get(link,headers = header) 
    soup = BeautifulSoup(res.text,'html.parser')

    title = soup.select('#title')
    name = title[0].text
    print('开始第%d个图片的线程.........'%n)
    #print(name)
    
    str = soup.select('#picurl')
    src = str[0]['href']

    #photo = requests.get(src)
   
    xuhao = src[42:]
    r = requests.get(src,stream = True)
    with open(r'C:\Users\Administrator\Desktop\photo\\' + xuhao,'wb') as f:           #保存地址
        for chunk in r.iter_content(chunk_size=32):
            f.write(chunk)
    print('*********已写入%d号图*******'%n)

   

#  开始
s = time.time()
url = 'http://bing.plmeizi.com/show/{}'
for n in range(735)[100:120]:                          #需要定期修改
    link = url.format(n)
    #print('写入第%d个图片.........'%n)
    thead = threading.Thread(target= bing,args=(link,n))
    thead.start()
thead.join()
e = time.time()
print('花费%.2fs下载'%(e-s))

                                