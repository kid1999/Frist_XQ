
import requests
from bs4 import BeautifulSoup
import jieba_fast as jieba
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




 
def count():                                            #统计字频
    with open (r'C:\Users\Administrator\Desktop\python计字频\斗破苍穹.txt','r') as f:
        str = f.read()
    words = jieba.cut(str)
    word = [x for x in words if len(x)>1]
    dict = Counter(word)
    print(dict)



def excel_write(count):                                           #创建excel文件  ，并且写excel  
    excel = xlwt.Workbook()                                  #建立excel工作空间  
        
    sheet1 = excel.add_sheet('小说统计')                      #创建sheet1，名字为小说统计  
        
    sheet1.write(0,0,'词语')                                  #写入的第一行，第1列写值    
    sheet1.write(0,1,'频数')                                  #写入的第一行，第2列写值 
    i = 0 
    for key,value in count.items():                            #循环写入值键对
        i= i+1
        sheet1.write(i,0,key)
        sheet1.write(i,1,value)  
    excel.save(r'C:\Users\Administrator\Desktop\python计字频\斗破字频统计表.xls') #保存excel







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


#  多进程 分词
s = time.clock()
if __name__ == '__main__':

    p = Pool()
    p.apply_async(count, )
    
    p.close()
    p.join()
e = time.clock()
print('分词花费%.2fs'%(e-s))

#多线程 写入
print('写入xls表中：..........')
write = threading.Thread(target=excel_write,args=(dict,))





