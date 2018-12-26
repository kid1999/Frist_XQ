from snownlp import SnowNLP

str = '我很喜欢你小可爱'
#with open(r'C:\Users\Administrator\Desktop\三种分词库的使用\斗破苍穹1.txt','r') as f:
    #str= f.read()
s = SnowNLP(str)

print('Sentiments情绪指数:', s.sentiments)                 #  。sentiments 情感分析
