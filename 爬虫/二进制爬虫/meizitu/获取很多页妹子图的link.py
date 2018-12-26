import requests
from bs4 import BeautifulSoup

#第一页的

link = 'http://www.mzitu.com/page/{}/'          #第二页开始的链接
for n in range(182)[1:]:                        #可以定期更新页码
    l = link.format(n)
    print(l)


