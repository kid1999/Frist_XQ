
# from django.http import HttpResponse
from django.shortcuts import render

def hello(request):
    context = {}
    context['hello'] = "hello world!"
    return render(request,'hello.html',context)

def index(request):
    return render(request,'index.html')