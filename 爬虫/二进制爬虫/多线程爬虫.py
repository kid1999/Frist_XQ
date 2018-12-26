#先把一个list网页拿出来
import requests
from bs4 import BeautifulSoup
import time
from multiprocessing import Process

link = 'http://www.dytt8.net/html/gndy/oumei/list_7_{}.html'

#首先定义函数
def get_url (link):
    for n in range(20000):
        url = link.format(n)
        print(url)
    
        #res = requests.get(link)
        #res.encoding = 'gb2312'
        #print(res.text)



#开始运行多进程:
if __name__ == '__main__':
    t = time.time()          #计时
    #run = Process(target=get_url,args=link)
    run = Process(target=get_url,args=(link,))
    run.start()

    print('所用时间:', time.time() - t) 

