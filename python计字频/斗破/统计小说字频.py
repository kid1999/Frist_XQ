import jieba
from collections import Counter
with open(r'C:\Users\Administrator\Desktop\计频分析\斗破苍穹.txt',"r",encoding='gb2312', errors='ignore') as f:
    str = f.read()
print(len(str))
words = jieba.cut(str)                      #划分词

word = [x for x in words if len(x)>1]       #将生成器数据转化为list
count = Counter(word)       #统计的是一个list
print(count)