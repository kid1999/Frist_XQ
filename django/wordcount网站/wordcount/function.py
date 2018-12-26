from  django.http import HttpResponse  #导入django的回应
from django.shortcuts import render      #传达一个网页



def home(request):  #用户的请求 -》 返回
    # return HttpResponse('你好！')   #来自django的回应

    return render(request,'home.html') #接收请求返回来自templates的URL

def count(request):
    text = request.GET['text']  #拿到提交的文本
    count = len(text)

    dict_text = {}
    for word in text:
        if word not in dict_text:
            dict_text[word] = 1
        else:
            dict_text[word] +=1
    
    sort = sorted(dict_text.items(),key=lambda e:e[1],reverse = True)


    return render(request,'count.html',{'text':text,'count':count,'count_word':dict_text,'sort':sort})#传给html的参数用dict


def about(request):  #用户的请求  返回
    return render(request,'about.html') #接收请求返回来自templates的URL