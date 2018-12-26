from snownlp import SnowNLP
from multiprocessing import Pool

def fenci(string):
    s = SnowNLP(string)
    result = s.words              
    print(len(result), '/'.join(result))                 #  。words 分词



    print('Sentiments:', s.sentiments)                 #  。sentiments 情感分析

with open(r'G:\python文件\qq爬虫\qq说说.txt','r',encoding='utf-8', errors='ignore') as f:
    string = f.read()
if __name__ == '__main__':

    p = Pool()
    p.apply_async(fenci,(string,))
    p.close()
    p.join()
    




