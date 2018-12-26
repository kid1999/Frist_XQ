import requests
from bs4 import BeautifulSoup    

def PC_xiazai(link):
#    第一部分:        拿取一页里面所有子连接的方法:....................
    res = requests.get(link)
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
PC_xiazai(link)

#    再拿后面25页的子连接,再拿取每一页的诗歌:

link = 'http://www.shicimingju.com/chaxun/zuozhe/1_{}.html'
for  n in range(26)[2:25]:
    l = link.format(n)
    print('*****************************第%d页********************************************************'%n)
    print('*****************************第%d页********************************************************'%n)
    print('*****************************第%d页********************************************************'%n)
    PC_xiazai(l)



