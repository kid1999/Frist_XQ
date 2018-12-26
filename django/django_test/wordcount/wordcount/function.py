from  django.http import HttpResponse  #导入django的回应
from django.shortcuts import render      #传达一个网页



def home(request):  #用户的请求 -》 返回
    # return HttpResponse('你好！')   #来自django的回应

    return render(request,'home.html') #接收请求返回来自templates的URL

def count(request):
    num = len(request.GET['text'])  #拿到提交的文本
    print(num)
    return render(request,'count.html')