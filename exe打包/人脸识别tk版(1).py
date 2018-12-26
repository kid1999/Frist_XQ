from tkinter import *
import tkinter.filedialog
from PIL import Image, ImageTk

import requests, sys
import ssl
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
    list = []
    request_url = "https://aip.baidubce.com/rest/2.0/face/v3/detect"
    base1 = get_photo_base(photo_url)  #上传图片

    params = "{\"image\":\""+base1+"\",\"image_type\":\"BASE64\",\"face_field\":\"faceshape,facetype,age,beauty,gender,glasses,race,facetype\",\"max_face_num\":\"10\"}" #传入参数
    access_token = '24.45d587b9112eca9fe1546c8bdec9b59b.2592000.1534653278.282335-11554113'
    request_url = request_url + "?access_token=" + access_token
    res = requests.post(url=request_url, data=params)
    result = res.json()
    for n in range(result['result']['face_num']):
        dict['face_num'] =  result['result']['face_num']                           #人脸数目
        dict['face_token'] =   result['result']['face_list'][n]['face_token']      #人脸图片的唯一标识
        dict['face_location'] =  result['result']['face_list'][n]['location']      #人脸在图片中的位置
        dict['age'] =  result['result']['face_list'][n]['age']                     #年龄
        dict['beauty'] = result['result']['face_list'][n]['beauty']                #美丽分
        dict['face_shape'] =   result['result']['face_list'][n]['face_shape']['type']     #square: 正方形 triangle:三角形 oval: 椭圆 heart: 心形 round: 圆形
        dict['gender'] =  result['result']['face_list'][n]['gender']['type']              #性别
        dict['face_type'] =   result['result']['face_list'][n]['face_type']['type']         #卡通/真人
        dict['glasses'] =   result['result']['face_list'][n]['glasses']['type']             #眼镜 
        dict['human_type'] =   result['result']['face_list'][n]['race']['type']             #人种
        print(dict)
        list.append(dict)
    try:
        print('正常运行')
        print(list)
        return list
    except:
        print('运行错误')
        return '文件错误!'




#放图:
#第一种
# img = PhotoImage(file=filename)  #仅支持gif
# ph = Label(root, text="图片",image=img)
# ph.pack()


#第二种:

# load = Image.open('pic.jpg') 
# render= ImageTk.PhotoImage(load)
# img = Label(root,text= '图片',image=render)

root = Tk()
root.title('人脸识图') #主窗口标题
root.geometry('600x300')  #主窗口大小，中间的为英文字母x

def xz():
    filename = tkinter.filedialog.askopenfilename()  #打开文本对话框


    if filename != '':
        lb.config(text = "您选择的文件是："+filename)
        lb.config(text = "图片信息如下:")
        got = get_result(filename)
        if got != '文件错误!':
            num = got[0]['face_num']
            for n in range(num):
                print(got[n])
                lb.config(text = "图中人数:%d 性别:%s 年龄:%d 脸型:%s 颜值:%.2f 真人/卡通:%s 眼镜:%s 人种:%s\n"%(num,got[n]['gender'],got[n]['age'],got[n]['face_shape'],got[n]['beauty'],got[n]['face_type'],got[n]['glasses'],got[n]['human_type']))
        else:
            lb.config(text = "文件错误!")
    else:
        lb.config(text = "您没有选择任何文件")




lb = Label(root,text = '')
lb.pack()
btn = Button(root,text="弹出选择文件对话框(选择一张人像)\n卡顿由于网络原因,请稍等!",command=xz)
btn.pack()
root.mainloop()






