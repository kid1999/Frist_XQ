from PIL import Image,ImageDraw,ImageFont
img = Image.open(r'C:\Users\Administrator\Desktop\百度人脸识别api\3.jpg')   #打开
#创建绘制对象
draw = ImageDraw.Draw(img)

#信息
location= {'left': 217.5687561, 'top': 206.6197815, 'width': 231, 'height': 223, 'rotation': -3}
x1= location['left']
y1= location['top']
x2= location['left'] + location['width']
y2= location['top'] + location['height']

#绘制直线:
#从a点到b点
draw.line((x1, y1, x1, y2), 'cyan')
draw.line((x1, y2, x2, y2), 'cyan')
draw.line((x2, y2, x2, y1), 'cyan')
draw.line((x2, y1, x1, y1), 'cyan')


#绘制文本
font = ImageFont.truetype("consola.ttf", 40, encoding="unic")#设置字体
number = 1
text = 'hello:%d'%(number)     #不支持中文
draw.text((x1, y1-30), text, 'fuchsia', font)
         #文字左上角坐标  内容  颜色    字体 

img.show()