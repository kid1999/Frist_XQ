
from django.http import HttpResponse
from TestModel.models import Test
import os

#数据库操作
def testdb(request):
    #first
    # test1 = Test(name = 'google')
    # test1.save()
    # return HttpResponse("<p>数据添加成功!</P>")

    #second 
    #init
    responese = ""
    responese1 = ""

    # list = Test.objects.all() #select * from 
    # responese2 = Test.objects.filter(id =1) #where
    # responese3 = Test.objects.get(id = 1) #获取单个对象
    # Test.objects.order_by('name')[:2]  #offset 0 limit 2
    # Test.objects.order_by('id') #rank

    #综合使用
    Test.objects.filter(name = 'kid').order_by('id')

    # 输出所有数据
    for var in list :
        responese1 += var.name + " "
    responese = responese1
    return HttpResponse("<p>" + responese + "</p>")


    
