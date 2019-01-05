import requests, sys
import ssl
import base64 
import json

#得到acess_token验证码
url = 'https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=LwciGoB63nAAYnB8PHi4kSoU&client_secret=aAtGzvxaUP83aOR1bOhy1pVfiD93sGNx'

d = {'Content-Type':'application/json','charset':'UTF-8'}
r = requests.post(url,data=d)
requests_json = r.json()                          #requests 内置的josn解析器 转化为dict
access_token = requests_json['access_token']
# print(access_token)                      #得到access_token



#将图片解析成base格式
def get_photo_base(photo_url):
    with open(photo_url,"rb") as f:
        base64_data = base64.b64encode(f.read())
        base = str(base64_data,'utf-8')
        return base



#上传对比
request_url = "https://aip.baidubce.com/rest/2.0/face/v3/match"
base1 = get_photo_base(r'E:\Git\history--code\百度人脸识别api\2.jpg')
base2 = get_photo_base(r'E:\Git\history--code\百度人脸识别api\3.jpg')

params = json.dumps(
    [{"image": base1, "image_type": "BASE64", "face_type": "LIVE", "quality_control": "LOW"},
     {"image": base2, "image_type": "BASE64", "face_type": "IDCARD", "quality_control": "LOW"}])

header = {'Content-Type':'application/json'}
request_url = request_url + "?access_token=" + access_token
res = requests.post(url=request_url, data=params,headers = header)
if res.json()['error_msg'] == 'SUCCESS':
    result = res.json()['result']['score']
    print('图片相似度为:',result)
else:
    result = res.json()
    print('错误原因:%d,   错误原因:%s'%(result['error_code'],result['error_msg']))