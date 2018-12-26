import requests, sys
import ssl
import base64 
import json
import MySQLdb





#写入数据库
db = MySQLdb.connect(host = 'localhost',#本地数据库

                             user = 'root', #用户名

                             passwd = '123456', #数据库密码

                             db = 'photo_ai', #数据库名

                             charset = 'utf8')  #数据库编码
db.ping(True)

print('链接到数据库......')






#得到acess_token验证码
def get_acess_token():
    url = 'https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=LwciGoB63nAAYnB8PHi4kSoU&client_secret=aAtGzvxaUP83aOR1bOhy1pVfiD93sGNx'
    d = {'Content-Type':'application/json','charset':'UTF-8'}
    r = requests.post(url,data=d)
    requests_json = r.json()                          #requests 内置的josn解析器 转化为dict
    access_token = requests_json['access_token']
    print(access_token)



#将图片解析成base格式
def get_photo_base(photo_url):
    with open(photo_url,"rb") as f:
        base64_data = base64.b64encode(f.read())
        base = str(base64_data,'utf-8')
        return base



#上传百度识别
def get_result(photo_url):
    request_url = "https://aip.baidubce.com/rest/2.0/face/v3/detect"
    base1 = get_photo_base(photo_url)  #上传图片

    params = "{\"image\":\""+base1+"\",\"image_type\":\"BASE64\",\"face_field\":\"faceshape,facetype,age,beauty,gender,glasses,race,facetype\",\"max_face_num\":\"10\"}" #传入参数
    access_token = '24.45d587b9112eca9fe1546c8bdec9b59b.2592000.1534653278.282335-11554113'               #  get_acess_token()
    request_url = request_url + "?access_token=" + access_token
    res = requests.post(url=request_url, data=params)
    result = res.json()

    #得到参数

    for n in range(result['result']['face_num']):

        face_num =  result['result']['face_num']                             #人脸数目
        face_token =   result['result']['face_list'][n]['face_token']        #人脸图片的唯一标识
        face_location =  result['result']['face_list'][n]['location']      #人脸在图片中的位置
        age =  result['result']['face_list'][n]['age']                       #年龄
        beauty = result['result']['face_list'][n]['beauty']                  #美丽分
        face_shape =   result['result']['face_list'][n]['face_shape']['type']       #square: 正方形 triangle:三角形 oval: 椭圆 heart: 心形 round: 圆形
        gender =  result['result']['face_list'][n]['gender']['type']                #性别
        face_type =   result['result']['face_list'][n]['face_type']['type']         #卡通/真人
        glasses =   result['result']['face_list'][n]['glasses']['type']             #眼镜 
        human_type =   result['result']['face_list'][n]['race']['type']             #人种

        # 执行sql语句
        sql = "insert into baidu_ai (photo_url,face_num,face_token,gender,age, beauty,face_shape,face_type,glasses,human_type) values('%s','%d','%s','%s','%d','%f','%s','%s','%s','%s')" % (photo_url,face_num,face_token,gender,age, beauty, face_shape,face_type,glasses,human_type)
        cursor = db.cursor()
        try:
            print(beauty)
            cursor.execute(sql)
            db.commit() #提交到数据库执行，一定要记提交哦 
            print('写入成功') 
            return face_location 
        except:  
            print('写入失败')



#opencv面部加框:
# def opencv()


#运行:

get_result(r'C:\Users\Administrator\Desktop\百度人脸识别api\4.jpg')




