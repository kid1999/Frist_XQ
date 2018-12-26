from django.shortcuts import render
from django.http import HttpResponse

def map(request):
    return render(request,'1.html')


#返回主页
def index(request):
    return render(request,'index.html')

#子网页返回
def one(request):
    return render(request,'男女分布.html')

def two(request):
    return render(request,'钦州学院大数据学生年龄分布.html')

def three(request):
    return render(request,'钦州学院大数据童鞋分布geo.html')
    
def four(request):
    return render(request,'大数据方向学生劣势科目.html')

def five(request):
    return render(request,'社团参与率.html')

def six(request):
    return render(request,'大学期盼.html')

def seven(request):
    return render(request,'大数据方向学生擅长科目.html')

def nine(request):
    return render(request,'大数据同学分布map.html')