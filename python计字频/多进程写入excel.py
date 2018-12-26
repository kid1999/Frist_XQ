
import jieba_fast as jieba
import time
from collections import Counter
import xlwt
import threading
from multiprocessing import Pool


def count():                                            #统计字频
    with open (r'C:\Users\Administrator\Desktop\python计字频\斗破苍穹1.txt','r') as f:
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




#  多进程 分词
s = time.clock()
if __name__ == '__main__':
    p = Pool()
    p.apply_async(count, )
    
    p.close()
    p.join()



e = time.clock()
print('分词写入花费%.2fs'%(e-s))






