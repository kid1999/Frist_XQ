from django.http import HttpResponse
from django.shortcuts import render
from ftplib import FTP
import re

#本次作业文件夹
path = 'e:\\test\\'

# 主页 
def index(request):
    return render(request,'index.html')

#  保存文件到本地

def upload(request):
    if request.method == "POST":
        try:
            f1 = request.FILES['myfile']
            #文件命名规范：
            pat = re.compile(r'\d{10}-[\u4e00-\u9fa5]{2,3}\-计科本171')
            if pat.findall(f1.name) :
                fname = path + f1.name                  # 修改 文件保存路径
                with open(fname, 'wb') as pic:
                    for c in f1.chunks():
                        pic.write(c)
                    return HttpResponse("ok   上传成功！")
            else:
                return HttpResponse("命名不规范！")
        except:
            return HttpResponse("no file!")
    else:
        return HttpResponse("error")












