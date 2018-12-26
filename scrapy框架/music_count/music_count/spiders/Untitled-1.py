import os
from Crypto.Cipher import AES
import base64
import codecs
import json
import scrapy
import re
from music_count.items import MusicCountItem

class music_Spider(scrapy.Spider):
    name = 'music_count'
    modulus = '00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7'
    nonce = '0CoJUm6Qyw8W8jud'
    pubKey = '010001'
    i=0
    page=10
    def __main__(self,i,page):
        self.i = i
        self.page = page

     #解密模块:

    def aesEncrypt(self,text, secKey):
        pad = 16 - len(text) % 16

        if isinstance(text,bytes):
            print("type(text)=='bytes'")
            text=text.decode('utf-8')

        text = text  + str(pad * chr(pad))
        encryptor = AES.new(secKey, 2, '0102030405060708')
        ciphertext = encryptor.encrypt(text)
        ciphertext = base64.b64encode(ciphertext)
        return ciphertext

    def rsaEncrypt(self,text,pubKey,modulus):
        text = text[::-1]

        rs = int(codecs.encode(text.encode('utf-8'),'hex_codec'), 16)**int(pubKey, 16)%int(modulus, 16)
        return format(rs, 'x').zfill(256)

    
    def createSecretKey(self,size):
        return (''.join(map(lambda xx: (hex(ord(xx))[2:]), str(os.urandom(size)))))[0:16]


#解密得到post密匙
    def get_payload(self,i):
        modulus = '00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7'
        nonce = '0CoJUm6Qyw8W8jud'
        pubKey = '010001'
        page = 10*i
        text = {
        'username': '',
        'password': '',
        'rememberLogin': 'true',
        'offset':str(page)
        }

        text = json.dumps(text)
        secKey = self.createSecretKey(16)                                    #密钥
        encText = self.aesEncrypt(self.aesEncrypt(text,nonce),secKey)           # 加入text 得到 params
        encSecKey = self.rsaEncrypt(text,pubKey,modulus)                 # 解密 得 enseckey
        payload = {
                    'params': encText,
                    'encSecKey': encSecKey
                }
        return payload

#拿到密匙,url开始爬虫

    def start_requests(self):
        with open(r'C:\Users\Administrator\Desktop\网易云\yu_music_number_list.txt','r') as f:
            lines = f.readlines()      #读取全部内容 ，并以列表方式返回  
            for music_id in lines :

                url = 'https://music.163.com/weapi/v1/resource/comments/R_SO_4_{}?csrf_token='
                url = url.format(music_id)
                while(self.i<self.page):
                    payload = self.get_payload(self.i)

                    yield scrapy.FormRequest(url = url,
                            method = 'POST',             # GET or POST
                            meta = payload,       # 自定义，向response传递数据
                            callback = self.parse_page,
                            dont_filter = True     # 如果需要多次提交表单，且url一样，那么就必须加此参数dont_filter，防止被当成重复网页过滤掉了
                            )



#爬虫内容:

    def parse_page(self,response,i):

        item = MusicCountItem()

        json_dict = json.loads(response.text)
        total_comment = json_dict['total']
        page=(total_comment/20)+1
        i = i+1
        print ('***查询到评论共计%d条,%d页***,现在是第 %d 页......................'%(total_comment,page,i))

        json_comment = json_dict['comments']
        for json_comment in json_comment:
            item['user_id'] = json_comment['user']['userId']
            item['user_name'] = json_comment['user']['nickname']
            item['comment'] = json_comment['content']
            likedCount = json_comment['likedCount']
            item['likedcount'] = int(likedCount)

            yield item,page







   
