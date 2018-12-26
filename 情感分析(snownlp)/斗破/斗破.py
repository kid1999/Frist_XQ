
import requests
from bs4 import BeautifulSoup


link = 'http://www.tianyabooks.com/net/tctd01/{}.html'  
for n in range(37900,39271):
    l = link.format(n)

    res = requests.get(l)
    res.encoding = 'gb2312'

    soup = BeautifulSoup(res.text,'html.parser')
    str = soup.select('p')
    print(str[1].text)
    with open(r'C:\Users\Administrator\Desktop\python计字频\斗破苍穹.txt',"a",encoding='gb2312', errors='ignore') as f:   #出现打开错误，直接复制路径打开报错，是因为”\”符号在python中会被视为转义符，此时传入的路径就出现差错；那我们可以采取修改路径的方式，将”\”改为”/”...在含有转义符的字符串前加‘r’表示字符串内按原始含义解释，不做转义处理；这里的r相当于正则表达的操作
        f.write(str[1].text)
    f.close()
