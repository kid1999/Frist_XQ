from snownlp import SnowNLP
from multiprocessing import Pool

def fenci(string):
    s = SnowNLP(string)
    result = s.words              
    print(len(result), '/'.join(result))                 #  。words 分词



    print('Sentiments:', s.sentiments)                 #  。sentiments 情感分析

with open(r'G:\python文件\情感分析\负面情感词语（中文）.txt','r') as f:
    str = f.read()
#str = '人生苦短，及时行乐。孩子们，儿童节快乐。你的心里下着雨，很想问你有没有带伞。'

if __name__ == '__main__':

    p = Pool()
    p.apply_async(fenci,(str,))
    p.close()
    p.join()
