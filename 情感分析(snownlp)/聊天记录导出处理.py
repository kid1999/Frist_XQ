import re
from jieba.analyse import *
from snownlp import SnowNLP


    

text = open(r'C:\Users\Administrator\Desktop\qq爬虫\新建文件夹\喻翠(1325966241).txt','r',encoding='utf-8', errors='ignore').read()


#提取时间:
def get_time():
    times = re.findall('(2018.*?)喻翠\n',text)
    print(times)
    for time in times:
        print(time)

#定义单句情绪分析:
def qingxu_number(text):
    s = SnowNLP(text)
    print('本句情绪指数:%f'%s.sentiments)

#定义单句关键词分析:
def get_guanjianzi(txt):
    guanjianzi = extract_tags(txt, withWeight=True)
    print('本句关键词%s'%guanjianzi)


#提取聊天
# 提取聊天记录中对方发来的文字写入新文件中:
f = open(r'C:\Users\Administrator\Desktop\qq爬虫\新建文件夹\find.txt','a',encoding='utf-8', errors='ignore')
texts = re.findall('喻翠\n(.*?)\n',text)
for txt in texts:
    if len(txt)!=0:
        print('聊天记录：%s'%txt)
        f.write(txt)



    
    

