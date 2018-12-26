import requests
image_url = 'http://i.meizitu.net/2018/04/29d01.jpg'

r = requests.get(image_url,stream = True)
with open(r'C:\Users\Administrator\Desktop\网易云爬虫\hello.jpg','wb') as f:
    for chunk in r.iter_content(chunk_size=32):
        f.write(chunk)