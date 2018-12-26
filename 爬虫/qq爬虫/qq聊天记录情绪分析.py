from snownlp import SnowNLP
import re

def fenxi(string):
    s = SnowNLP(string)
    print('Sentiments指数:', s.sentiments)                 #  。sentiments 情感分析


text = open(r'C:\Users\Administrator\Desktop\qq爬虫\新建文件夹\喻翠(1325966241).txt','r',encoding='utf-8', errors='ignore').read()
texts = re.findall('喻翠\n(.*?)\n',text)
for txt in texts:
    if len(txt) !=0:
        print(txt)
        fenxi(txt)
        



