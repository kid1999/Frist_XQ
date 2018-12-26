import re
from jieba import analyse


#TF_IDF算法:
tfidf = analyse.extract_tags
#TextRANK算法:
#textrank = analyse.extract_tags

#定义单句关键词分析:

text = open(r'C:\Users\Administrator\Desktop\qq爬虫\新建文件夹\许艳玲(1741775603).txt','r',encoding='utf-8', errors='ignore').read()
find = open(r'C:\Users\Administrator\Desktop\qq爬虫\新建文件夹\许艳玲关键词.txt','a',encoding='utf-8', errors='ignore')
texts = re.findall('数应本171许艳玲\n(.*?)\n',text)
for txt in texts:
    guanjianzi = tfidf(txt)
    for keyword in guanjianzi:
        print('本句关键词%s'%keyword)
        find.write(keyword)
        find.write(' ')





 