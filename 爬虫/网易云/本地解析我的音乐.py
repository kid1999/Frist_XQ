from bs4 import BeautifulSoup
import re 
 #事先下载好我的列表
with open(r'C:\Users\Administrator\Desktop\网易云\my_music_list.txt','r') as f:  
    url_text = f.read()

soup = BeautifulSoup(url_text,'html.parser')
with open(r'C:\Users\Administrator\Desktop\网易云\music_number_list.txt','a') as f:
    for url_text in soup.select('.txt a'):
        str = url_text['href']
        pattern = re.compile(r'\d+')   # 正则表达式 搞定music——id
        music_number = pattern.findall(str)
        print(music_number)
        f.write(music_number[0])
        f.write('\n')


