import requests
image_url = 'https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1525017234824&di=55fab9dd455b2e16c7ddb96900e5c751&imgtype=0&src=http%3A%2F%2Fs9.rr.itc.cn%2Fr%2FwapChange%2F20174_23_16%2Fa9kjd72319273176542.jpg'


r = requests.get(image_url,stream = True)
with open(r'C:\Users\Administrator\Desktop\网易云爬虫\hello.jpg','wb') as f:
    for chunk in r.iter_content(chunk_size=32):
        f.write(chunk)
        