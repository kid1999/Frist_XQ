from tkinter import Label,Button
import tkinter.filedialog
from PIL import Image, ImageTk,ImageDraw,ImageFont
from collections import defaultdict
import requests 
import base64 
import json

#先定义方式库:


#将图片解析成base格式
def get_photo_base(photo_url):
    with open(photo_url,"rb") as f:
        base64_data = base64.b64encode(f.read())
        base = str(base64_data,'utf-8')
        return base



#上传对比
def get_result(photo_url):
    dict = {}
    dict =defaultdict(list)                  #初始化定义dict
    request_url = "https://aip.baidubce.com/rest/2.0/face/v3/detect"
    base1 = get_photo_base(photo_url)  #上传图片

    params = "{\"image\":\""+base1+"\",\"image_type\":\"BASE64\",\"face_field\":\"faceshape,facetype,age,beauty,gender,glasses,race,facetype\",\"max_face_num\":\"10\"}" #传入参数
    access_token = '24.ff8a9e09dcf23bfc3be3c6773b77196c.2592000.1542379536.282335-11554113'
    request_url = request_url + "?access_token=" + access_token
    res = requests.post(url=request_url, data=params)
    result = res.json()
    for n in range(result['result']['face_num']):
        dict['face_num'].append(result['result']['face_num'])                           #人脸数目
        dict['face_token'].append(result['result']['face_list'][n]['face_token'])     #人脸图片的唯一标识
        dict['face_location'].append(result['result']['face_list'][n]['location'])      #人脸在图片中的位置
        dict['age'].append(result['result']['face_list'][n]['age'] )                    #年龄
        dict['beauty'].append(result['result']['face_list'][n]['beauty'] )               #美丽分
        dict['face_shape'].append(result['result']['face_list'][n]['face_shape']['type'])     #square: 正方形 triangle:三角形 oval: 椭圆 heart: 心形 round: 圆形
        dict['gender'].append(result['result']['face_list'][n]['gender']['type'] )             #性别
        dict['face_type'].append(result['result']['face_list'][n]['face_type']['type'])         #卡通/真人
        dict['glasses'].append(result['result']['face_list'][n]['glasses']['type'] )            #眼镜 
        dict['human_type'].append(result['result']['face_list'][n]['race']['type'])             #人种

    try:
        print('正常运行:')
        print('返回的list信息:',dict)
        return dict
    except:
        print('运行错误')
        return '文件错误!'



#图像处理部分:
def deal_photo(filename,n,dict):
    img_url = Image.open(filename)   #打开
    #创建绘制对象
    draw = ImageDraw.Draw(img_url)
    for n in range(n):
        location= dict['face_location'][n]

    # location: [{'left': 493.7315674, 'top': 361.2690735, 'width': 65, 'height': 64, 'rotation': -5}, {'left': 361.9848938, 'top': 391.3988953, 'width': 63, 'height': 59, 'rotation': 2}]
        x1= location['left']
        y1= location['top']
        x2= location['left'] + location['width']
        y2= location['top'] + location['height']

        draw.line((x1, y1, x1, y2), 'cyan')
        draw.line((x1, y2, x2, y2), 'cyan')
        draw.line((x2, y2, x2, y1), 'cyan')
        draw.line((x2, y1, x1, y1), 'cyan')

        #绘制文本
        font = ImageFont.truetype("consola.ttf", 20, encoding="unic")#设置字体
        text = 'number:%d'%(n)                                       # 不支持中文
        draw.text((x1, y1-15), text, 'fuchsia', font)

    img = ImageTk.PhotoImage(img_url)                               #将修改后的图片传递给tk
    return img



def xz():
    filename = tkinter.filedialog.askopenfilename()
    global img
#识别显示:
    if filename != '':
        lb.config(text = "您选择的文件是："+filename)
        lb.config(text = "连接超时,请重试")
        dict = get_result(filename)
        if dict != '文件错误!':
            num = dict['face_num'][0]
            img = deal_photo(filename,num,dict)           #得到改造后的图片 
            l1.config(image=img)                         #重新配置得改变的照片(label不会自己改变)
            text = ''
            for n in range(num):
                str = "人物编号:%d 性别:%s 年龄:%d 脸型:%s 颜值:%.2f 真人/卡通:%s 眼镜:%s 人种:%s\n"%(n,dict['gender'][n],dict['age'][n],dict['face_shape'][n],dict['beauty'][n],dict['face_type'][n],dict['glasses'][n],dict['human_type'][n])
                text = text + str
            lb.config(text = text)                        
        else:
            lb.config(text = "文件错误!")
    else:
        lb.config(text = "您没有选择任何文件")


#开始 gui事件:
img = ''                                                                   #初始赋值
root = tkinter.Tk()
root.title('人脸识图')                                                      #主窗口标题
lb = Label(root,text = '')                                                 #lebal框
lb.pack()                                                                  #pack放到窗口上
btn = Button(root,text="(选择一张人像)\n卡顿由于网络原因,请稍等!",command=xz)  #按键框
btn.pack()
l1=Label(root)                                                             #图片框
l1.pack()
root.mainloop()






