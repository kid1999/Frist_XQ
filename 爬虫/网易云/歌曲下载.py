import requests
import time
import wget


def download(key,id):
    music_url = 'http://music.163.com/song/media/outer/url?id={}.mp3'   #传入的数字必须是int 不是str
    url = music_url.format(id)
    address = 'C:\\Users\\Administrator\\Desktop\\网易云\\music\\'+ key +'.mp3'
    print('下载:',key)
    wget.download(url, out=address)



#循环传入 id:
start_time = time.time()
with open(r'C:\Users\Administrator\Desktop\网易云\music_number_list.txt','r',encoding='utf-8') as f:
    lines = f.readlines()      #读取全部内容 ，并以列表方式返回  
    for line in lines: 
        try:
            key,value=line.split(",")
            id = int(value) 
        except:
            print(key,'歌名格式错误')
        try:
            print('开始下载:',key)
            download(key,id)
        except:
            print('歌曲已下架')


     

end_time = time.time()
print('下载所用时间为：%.2fs'%(end_time- start_time))



