
import requests
from bs4 import BeautifulSoup
import jieba
from collections import Counter
import time
import xlwt
import threading
from multiprocessing import Process,Pool




def  jiexi(link):                                       #网页爬取小说

    res = requests.get(link)
    res.encoding = 'gb2312'

    soup = BeautifulSoup(res.text,'html.parser')
    str = soup.select('p')
    #print(str[1].text)                                #保存到本地

    with open(r'C:\Users\Administrator\Desktop\python计字频\斗破苍穹.txt',"a",encoding='gb2312', errors='ignore') as f:   #出现打开错误，直接复制路径打开报错，是因为”\”符号在python中会被视为转义符，此时传入的路径就出现差错；那我们可以采取修改路径的方式，将”\”改为”/”...在含有转义符的字符串前加‘r’表示字符串内按原始含义解释，不做转义处理；这里的r相当于正则表达的操作
        f.write(str[1].text)
    f.close()




#第一类:     多线程 爬虫 写入

link = 'http://www.tianyabooks.com/net/tctd01/{}.html'
c= 0 
start_time = time.time() 
for n in range(37900,39271):        
    c= c+1
    l = link.format(n)
    print('第%d章'%c)
    xiazai = threading.Thread(target = jiexi,args=(l,))          #创建线程
    xiazai.start()



xiazai.join()                    #  限速
end_time = time.time()
print('下载小说所用时间为：%.2fs'%(end_time- start_time))









