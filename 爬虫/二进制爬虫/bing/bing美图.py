import requests
from bs4 import BeautifulSoup
url = 'http://bing.plmeizi.com/show/{}'
for n in range(735)[::-1]:
    link = url.format(n)
    header = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36'}

    res = requests.get(link,headers = header) 
    soup = BeautifulSoup(res.text,'html.parser')

    title = soup.select('#title')
    name = title[0].text
    
    str = soup.select('#picurl')
    src = str[0]['href']

    print('写入第%d个图片'% n)

    photo = requests.get(src)
   
    xuhao = src[42:]
    r = requests.get(src,stream = True)
    with open(r'C:\Users\Administrator\Desktop\photos\\' + xuhao,'wb') as f:
        for chunk in r.iter_content(chunk_size=32):
            f.write(chunk)

   




