# -*- coding: utf-8 -*-

from django.shortcuts import render
from django.views.decorators import csrf

#接收post请求数据
def search_post(request):       #  自刷新页面
    ctx = {}
    if request.POST:
        ctx['rlt'] = request.POST['q']
    return render(request,'post.html',ctx)
    