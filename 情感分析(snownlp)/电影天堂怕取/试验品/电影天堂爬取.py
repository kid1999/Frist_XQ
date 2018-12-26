import requests
from bs4 import BeautifulSoup
res = requests.get('http://www.dytt8.net/html/gndy/dyzz/index.html')
res.encoding = 'gb2312'
soup = BeautifulSoup(res.text,'html.parser')


for title in soup.select('.co_content8 table a'):
    a = title.text
    b = 'http://www.dytt8.net' + title['href']
    print(a,b)
    
