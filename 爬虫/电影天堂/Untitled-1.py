import requests
from bs4 import BeautifulSoup



res = requests.get('http://www.dytt8.net/html/gndy/jddy/20160320/50523.html')
res.encoding = 'gb2312'
soup = BeautifulSoup(res.text,'html.parser')


title =  soup.select('.co_content8 a')
url = title['href']
print(url)

res = requests.get(url)
res.encoding = 'gb2312'

soup = BeautifulSoup(res.text,'html.parser')
str = soup.select('.co_content8 td a')
if len(str)==1:
    print(str[0].text)
