import os
from Crypto.Cipher import AES
import base64
import codecs
import re
import json
import requests
import MySQLdb




#解密模块:

def aesEncrypt(text, secKey):
	pad = 16 - len(text) % 16

	if isinstance(text,bytes):
		print("type(text)=='bytes'")
		text=text.decode('utf-8')

	text = text  + str(pad * chr(pad))
	encryptor = AES.new(secKey, 2, '0102030405060708')
	ciphertext = encryptor.encrypt(text)
	ciphertext = base64.b64encode(ciphertext)
	return ciphertext

def rsaEncrypt(text, pubKey, modulus):
	text = text[::-1]

	rs = int(codecs.encode(text.encode('utf-8'),'hex_codec'), 16)**int(pubKey, 16)%int(modulus, 16)
	return format(rs, 'x').zfill(256)

modulus = '00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7'
nonce = '0CoJUm6Qyw8W8jud'
pubKey = '010001'

def createSecretKey(size):
	return (''.join(map(lambda xx: (hex(ord(xx))[2:]), str(os.urandom(size)))))[0:16]

def get_text(i):
    page = 10*i
    text = {
    'username': '',
    'password': '',
    'rememberLogin': 'true',
    'offset':str(page)
    }
    return text

#开始工作：
def get_music_comment(music_name,music_id):

    url = 'https://music.163.com/weapi/v1/resource/comments/R_SO_4_{}?csrf_token='
    url = url.format(music_id)

    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.62 Safari/537.36'}


    i = 0                    #从第一页开始
    page = 10
    while (i<page):

        text = json.dumps(get_text(i))
        secKey = createSecretKey(16)                                    #密钥
        encText = aesEncrypt(aesEncrypt(text, nonce), secKey)           # 加入text 得到 params
        encSecKey = rsaEncrypt(secKey, pubKey, modulus)                 # 解密 得 enseckey
        payload = {
                    'params': encText,
                    'encSecKey': encSecKey
                }

        res = requests.post(url,headers = headers,data=payload)

        json_dict = json.loads(res.text)
        total_comment = json_dict['total']
        page=(total_comment/20)+1
        i= i+1
        print ('***查询到评论共计%d条,%d页***,现在是第 %d 页......................'%(total_comment,page,i))

        json_comment = json_dict['comments']
        for json_comment in json_comment:
            user_id = json_comment['user']['userId']
            user_name = json_comment['user']['nickname']
            comment = json_comment['content']
            likedcount = json_comment['likedCount']
            likedCount = int(likedcount)
            print('歌名:',music_name)
            print('用户id:',user_id)
            print('用户名:',user_name)
            print('评论:',comment)
            print('点赞数:',likedCount)
       # 执行sql语句
            sql = "insert into music(music_id,music_name,user_id, user_name, comment, likedcount) values('%s','%s','%s','%s', '%s', '%d')" % (music_id,music_name,user_id,user_name,comment,likedCount)
            cursor = db.cursor()
            try:
                cursor.execute(sql)
                db.commit() #提交到数据库执行，一定要记提交哦 
                print('写入成功') 
            except:  
                print('写入失败')


#写入数据库
db = MySQLdb.connect(host = 'localhost',#本地数据库

                             user = 'root', #用户名

                             passwd = '123456', #数据库密码

                             db = 'music_comment', #数据库名

                             charset = 'utf8')  #数据库编码

print('链接到数据库......')

#遍历我所有的歌:
with open(r'C:\Users\Administrator\Desktop\网易云\yu_music_number_list.txt','r',encoding='utf-8') as f:
    lines = f.readlines()      #读取全部内容 ，并以列表方式返回  
    for line in lines :  
        key,value=line.split(",")   
        get_music_comment(key,value)


# 关闭数据库连接
db.close()