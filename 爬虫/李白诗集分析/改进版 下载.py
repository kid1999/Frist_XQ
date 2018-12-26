import requests
from bs4 import BeautifulSoup 
import threading


headers = {'Host': 'www.shicimingju.com',
'Connection': 'keep-alive',
'Cache-Control': 'max-age=0',
'Upgrade-Insecure-Requests': '1',
'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36',
'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
'Referer':'http://www.shicimingju.com/chaxun/zuozhe/1.html',
'Accept-Encoding':'gzip, deflate',
'Accept-Language': 'zh-CN,zh;q=0.9'
} 



def PC_xiazai(link,headers):
#    第一部分:        拿取一页里面所有子连接的方法:....................

    res = requests.get(link,headers = headers)
    soup = BeautifulSoup(res.text,'html.parser')

    #主页面正文：
    for title in soup.select('h3'):
        title = title.select('a')
        name = title[0].text
        zi_link = 'http://www.shicimingju.com' + title[0]['href']
        print(name)
        #print(zi_link)

        #第二部分 ：     拿每一页的内容：.......................
        res = requests.get(zi_link)
        soup = BeautifulSoup(res.text,'html.parser')

        #子页面正文：
        title = soup.select('.shici-content')
        sige = title[0].text
        #print(sige)

        #第三部分：      保存内容
        with open(r'C:\Users\Administrator\Desktop\李白诗集分析\李白诗集.txt','a') as f:
            f.write(name)
            f.write(sige)
        f.close()






#   先拿第一页的所有子连接,再拿取每一页的诗歌:

link = 'http://www.shicimingju.com/chaxun/zuozhe/1.html'
PC_xiazai(link,headers)

#    再拿后面25页的子连接,再拿取每一页的诗歌:

link = 'http://www.shicimingju.com/chaxun/zuozhe/1_{}.html'
for  n in range(26)[2:25]:
    l = link.format(n) 
    t = threading.Thread(target=PC_xiazai,args=(l,headers))
    t.start()
t.join()



