import base64 
with open(r'C:\Users\Administrator\Desktop\百度人脸识别api\2.jpg',"rb") as f:
    # b64encode是编码，b64decode是解码
    base64_data = base64.b64encode(f.read())
    # print(base64_data) #带有b''编码
    print(str(base64_data,'utf-8'))  #用utf-8解码即可