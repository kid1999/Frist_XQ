import xlwt
import requests
from bs4 import BeautifulSoup


file = xlwt.Workbook()
table = file.add_sheet('first list')
table.write(0,0,'电影名')
table.write(0,1,'迅雷链接')


def add_xls(name,title):
    print('写入xls中...... %s'%name)
    table.write(i,0,name)
    table.write(i,1,title)

i = 1
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

            res = requests.get(url)                               #解析单个电影网址
            res.encoding = 'gb2312'
            soup = BeautifulSoup(res.text,'html.parser')

            title = soup.select('.co_content8 td  a')
            if len(title) !=0 :             #获取迅雷链接
                title = title[0].text
                
                                                
                add_xls(name,title)
                i = i+1
                if i >=300 :                   #输入你需要的数量
                    file.save(r'C:\Users\Administrator\Desktop\电影天堂怕取\text2.xls')    #修改你的保存地址
                    print('写入完成!')
                    exit()






