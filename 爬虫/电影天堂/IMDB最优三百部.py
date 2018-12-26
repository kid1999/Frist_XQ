import requests
from bs4 import BeautifulSoup



res = requests.get('http://www.ygdy8.com/html/gndy/jddy/20171128/55649.html')
res.encoding = 'gb2312'

soup = BeautifulSoup(res.text,'html.parser')
str = soup.select('.co_content8 td a')
print(str[0].text)