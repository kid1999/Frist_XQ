from collections import Counter
import jieba_fast as jieba
with open(r'C:\Users\Administrator\Desktop\三种分词库的使用\斗破苍穹1.txt',"r",encoding='gb2312', errors='ignore') as f:
    str = f.read()
print(len(str))
words = jieba.cut(str)                      #划分词
word = [x for x in words if len(x)>1]       #将生成器数据转化为list
count = Counter(word).most_common(5)        #统计频率前五的词
print(count)
