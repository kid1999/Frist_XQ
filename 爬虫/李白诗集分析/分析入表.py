import jieba_fast as jieba
from collections import Counter
import xlwt
import time


start_time = time.time()
with open(r'C:\Users\Administrator\Desktop\李白诗集分析\李白诗集.txt','r',encoding='gb2312', errors='ignore') as f:
    str = f.read()

words = jieba.cut(str)
word = [x for x in words if len(x)>1]
count = Counter(word)
print(count)

print('开始写入excel......')



#创建excel文件  ，并且写excel  
excel = xlwt.Workbook()                                     #建立excel工作空间  
    
sheet1 = excel.add_sheet('小说统计')                      #创建sheet1，名字为小说统计  
    
sheet1.write(0,0,'词语')                                  #写入的第一行，第1列写值    
sheet1.write(0,1,'频数')                                  #写入的第一行，第2列写值 
i = 0 
for key,value in count.items():
    i= i+1

    sheet1.write(i,0,key)
    sheet1.write(i,1,value)  
excel.save(r'C:\Users\Administrator\Desktop\李白诗集分析\李白诗歌字频统计表.xls') #保存excel
print('写入完成.....')
end_time = time.time()
print('花费时间为%.2fs'%(end_time-start_time))  


