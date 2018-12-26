
import requests
from bs4 import BeautifulSoup
import jieba_fast as jieba
from collections import Counter
import time
import xlwt
import threading
from multiprocessing import Process,Pool





#              面向对象:

class MyThread(threading.Thread): # 这个类的一个实例就是代表了一个线程，然后通过重载这个类中的run方法（是run，不是start！！但start的动作确实就是调用run）来执行具体的操作。
    def __init__(self,arg):
        super(MyThread, self).__init__()#注意：一定要显式的调用父类的初始化函数。
        self.arg=arg

    def  jiexi(self):                                       #多线程爬取小说


        res = requests.get(self.arg)
        res.encoding = 'gb2312'

        soup = BeautifulSoup(res.text,'html.parser')
        str = soup.select('p')
        print(str[1].text)                                #保存到本地

        with open(r'C:\Users\Administrator\Desktop\python计字频\斗破苍穹.txt',"a",encoding='gb2312', errors='ignore') as f:   #出现打开错误，直接复制路径打开报错，是因为”\”符号在python中会被视为转义符，此时传入的路径就出现差错；那我们可以采取修改路径的方式，将”\”改为”/”...在含有转义符的字符串前加‘r’表示字符串内按原始含义解释，不做转义处理；这里的r相当于正则表达的操作
            f.write(str[1].text)
        f.close()

                                       

    



 
def count():                                            #多进程统计字频
    with open (r'C:\Users\Administrator\Desktop\python计字频\斗破苍穹.txt','r') as f:
        str = f.read()
    words = jieba.cut(str)
    word = [x for x in words if len(x)>1]
    t = Counter(word)

    excel = xlwt.Workbook()                                     #建立excel工作空间  
            
    sheet1 = excel.add_sheet('小说统计')                      #创建sheet1，名字为小说统计  
            
    sheet1.write(0,0,'词语')                                  #写入的第一行，第1列写值    
    sheet1.write(0,1,'频数')                                  #写入的第一行，第2列写值 
    i = 0 
    for key in t:
        i= i+1

        sheet1.write(i,0,key)
        sheet1.write(i,1,t[key]) 
    excel.save(r'C:\Users\Administrator\Desktop\python计字频\统计表1.xls') 


#多线程 下载

link = 'http://www.tianyabooks.com/net/tctd01/{}.html'
c= 0 
start_time = time.time() 
for n in range(37900,39271):         #创建线程
    c= c+1
    l = link.format(n)
    #print('第%d章'%c)
    t = MyThread(l)                       #引用继承的thead
    t.start()

    #t.join()
end_time = time.time()
print('下载小说所用时间为：%.2fs'%(end_time- start_time))


  


#  多进程 分词写入
s = time.clock()
if __name__ == '__main__':
    p = Pool()
    p.apply_async(count, )
    
    p.close()
    p.join()
e = time.clock()
print('分词花费%.2fs'%(e-s))