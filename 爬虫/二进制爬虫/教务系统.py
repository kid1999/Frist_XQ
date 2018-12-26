import requests
from bs4 import BeautifulSoup
import os

headers = {'User-Agent':"Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36"
           ,'Referer':'http://116.13.207.7/default2.aspx',
           'cookie':'ASP.NET_SessionId=q52smo45nahxzemcnfjaup45'}

#url = 'http://116.13.207.7/xs_main.aspx?xh=1704405135'
url = 'http://116.13.207.7/xsgrxx.aspx?xh=1704405135&xm=%CF%C8%D3%D1%C8%AB&gnmkdm=N121501'

res = requests.get(url,headers = headers)   #获取页面
soup = BeautifulSoup(res.text,'html.parser')

xuehao = soup.select('#xh')
print( xuehao[0].text)
name = soup.select('#xm')
print( name[0].text)
banji = soup.select('#lbl_xzb')
print(banji[0].text)

