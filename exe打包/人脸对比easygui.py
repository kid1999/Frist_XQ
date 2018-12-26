import requests
import base64 
import json
from easygui import fileopenbox,msgbox,exceptionbox


#将图片解析成base格式
def get_photo_base(photo_url):
    with open(photo_url,"rb") as f:
        base64_data = base64.b64encode(f.read())
        base = str(base64_data,'utf-8')
        return base



#上传对比
def get_result(path1,path2):
    request_url = "https://aip.baidubce.com/rest/2.0/face/v3/match"
    base1 = get_photo_base(path1)
    base2 = get_photo_base(path2)

    params = json.dumps(
        [{"image": base1, "image_type": "BASE64", "face_type": "LIVE", "quality_control": "LOW"},
        {"image": base2, "image_type": "BASE64", "face_type": "IDCARD", "quality_control": "LOW"}])

    header = {'Content-Type':'application/json'}
    request_url = request_url + "?access_token=" + '24.45d587b9112eca9fe1546c8bdec9b59b.2592000.1534653278.282335-11554113' 
    res = requests.post(url=request_url, data=params,headers = header)
    if res.json()['error_msg'] == 'SUCCESS':
        try:
            result = res.json()['result']['score']
            return result
        except:
            return '网络连接错误'
    else:
        result = res.json()
        print('错误原因:%d,   错误原因:%s'%(result['error_code'],result['error_msg']))
        return result['error_msg']




#精简版：
try:
    msg = msgbox("请选择2张图进行对比!") 
    path1 = fileopenbox( 'title=请选择需要被对比的原图！',default = r"C:\Users\Administrator\Desktop\百度人脸识别api\*")
    path2 = fileopenbox( 'title=请选择对比的图！',default = r"C:\Users\Administrator\Desktop\百度人脸识别api\*")
    r = get_result(path1,path2)
    if type(r) is str:
        text =  str(r)
    else:
        text ='相似度：' +  str(r)
    msg = msgbox(text)
except:
    exceptionbox()


#完善版本：
# msg = msgbox("请选择需要被对比的原图!") 
# path1 = fileopenbox( 'title=请选择需要被对比的原图！',default = r"C:\Users\Administrator\Desktop\百度人脸识别api\*")

# msg = msgbox("请选择对比的图！开始测试！")
# path2 = fileopenbox( 'title=请选择对比的图！',default = r"C:\Users\Administrator\Desktop\百度人脸识别api\*")

# if ccbox("",choices=("开始测试！","继续选图！")):
#     path2 = path2
#     r = get_result(path1,path2)
#     text ='相似度：' +  str(r)
#     msg = msgbox(text) 
# else:
#     path2 = fileopenbox( 'title=请选择对比的图！')



 






