
#无ui版

import requests
from bs4 import BeautifulSoup



#        使用时调用a/b/c函数                                            创建三个分类函数: 分别获取各种类的 name 与 具体一个电影对应的url

#欧美
def a():

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

                title = soup.select('.co_content8 td  a')             #获取迅雷链接
                title = title[0].text
                                                
                print(name  + '   的迅雷链接是:')                    #打印结果
                print(title)
                        
    
#华语
def b():
    
    link = 'http://www.ygdy8.net/html/gndy/china/list_4_{}.html'
    for n in range(1,103):
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

                title = soup.select('.co_content8 td  a')             #获取迅雷链接
                title = title[0].text
                                                
                print(name  + '   的迅雷链接是:')                    #打印结果
                print(title)
                                   
            

#日韩


link = 'http://www.ygdy8.net/html/gndy/rihan/list_6_{}.html'
for n in range(1,33):
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

            title = soup.select('.co_content8 td  a')             #获取迅雷链接
            title = title[0].text
                                            
            print(name  + '   的迅雷链接是:')                    #打印结果
            print(title)

                      #强行凑齐99行召唤神龙









