#先把一个list网页拿出来
import requests
from bs4 import BeautifulSoup

link = 'http://www.dytt8.net/html/gndy/oumei/list_7_{}.html'
for n in range(1,190):
    l = link.format(n)
    res = requests.get(l)
    res.encoding = 'gb2312'
    soup = BeautifulSoup(res.text,'html.parser')


    for title in soup.select('.co_content8 table a'):
        name = title.text 
        
        if len(title['href']) == 35:
   
        
            url = 'http://www.dytt8.net' + title['href']
            
            print(name  + '   的迅雷链接是:')
            print(url)
   