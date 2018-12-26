
import requests
from bs4 import BeautifulSoup


link = 'http://m.ksw8888.com/wangluo/shinianyipinwenruyan/{}.html'  
for n in range(149553,149579)[::-1]:
    l = link.format(n)

    res = requests.get(l)
    res.encoding = 'gb2312'

    soup = BeautifulSoup(res.text,'html.parser')
    str = soup.select('.articleContent')
    print(str[0].text)
    with open(r'C:\Users\Administrator\Desktop\vs code\90---.txt',"a",encoding='gb2312', errors='ignore') as f:   #出现打开错误，直接复制路径打开报错，是因为”\”符号在python中会被视为转义符，此时传入的路径就出现差错；那我们可以采取修改路径的方式，将”\”改为”/”...在含有转义符的字符串前加‘r’表示字符串内按原始含义解释，不做转义处理；这里的r相当于正则表达的操作
        f.write(str[0].text )
    f.close()
