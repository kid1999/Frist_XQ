from bs4 import BeautifulSoup
import re 
 #事先下载好我的列表
with open(r'C:\Users\Administrator\Desktop\网易云\my_music_list.txt','r') as f:  
    url_text = f.read()

soup = BeautifulSoup(url_text,'html.parser')
with open(r'C:\Users\Administrator\Desktop\网易云\music_number_list.txt','a',encoding='utf-8') as f:
    for url_text in soup.select('.txt a'):

        ok = re.findall(r' title="(.*?)".*',str(url_text))
        print(ok)

        str1 = url_text['href']
        music_number = re.findall(r'\d+',str1)
        print(music_number)


        f.write(ok[0])
        f.write(',')
        f.write(music_number[0])
        f.write('\n')
 #歌名写入
        

