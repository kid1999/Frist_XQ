from snownlp import SnowNLP
from multiprocessing import Pool

def fenci(string):
    s = SnowNLP(string)
    result = s.words              
    print(len(result), '/'.join(result))                 #  。words 分词



    print('Sentiments:', s.sentiments)                 #  。sentiments 情感分析

with open(r'C:\Users\Administrator\Desktop\李白诗集分析\李白诗集.txt','r',encoding='gb2312', errors='ignore') as f:
    string = f.read()
if __name__ == '__main__':

    p = Pool()
    p.apply_async(fenci,(string,))
    p.close()
    p.join()
    




