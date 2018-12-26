import requests
from bs4 import BeautifulSoup

link = 'http://www.ygdy8.net/html/gndy/china/list_4_{}.html'
for n in range(1,103):
    l = link.format(n)
    
    res = requests.get(l)
    res.encoding = 'gb2312'
    soup = BeautifulSoup(res.text,'html.parser')


        
    for title in soup.select('.co_content8 table a'):
        name = title.text 
        print(name)
            
        if len(title['href']) == 35:
    
            
            url = 'http://www.dytt8.net' + title['href']
            print(url)

            res = requests.get(url)                               #解析单个电影网址
            res.encoding = 'gb2312'
            soup = BeautifulSoup(res.text,'html.parser')

            
            title = soup.select('.co_content8 td a')
            
            print(title[0].text)  
                  

                                            

