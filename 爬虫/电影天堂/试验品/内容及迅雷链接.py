import requests
from bs4 import BeautifulSoup
res = requests.get('http://www.dytt8.net/html/gndy/dyzz/20180322/56549.html')
res.encoding = 'gb2312'
soup = BeautifulSoup(res.text,'html.parser')

title = soup.select('.co_content8 td  a')
title = title[0].text
print(title)

