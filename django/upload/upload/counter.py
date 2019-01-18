from __future__ import unicode_literals
import math
import os
from django.http import HttpResponse
from django.template import loader
from pyecharts import Line3D,Gauge


REMOTE_HOST = "https://pyecharts.github.io/assets/js"
path = 'd:\\test\\'
log_path = 'C:\\log\\'

def count(request):
#     write_txt()     # 写入日志
    people = dispaly_people()  # 展示
    if not people:
        return HttpResponse("无上交记录!")
    template = loader.get_template('count.html')
    l3d = display()
    context = dict(
        myechart=l3d.render_embed(),
        host=REMOTE_HOST,
        script_list=l3d.get_js_dependencies(),
        people_num= len(os.listdir(path)),
        people_dict=people
    )
    return HttpResponse(template.render(context, request))


        #仪表盘显示
def display():
    num = int((len(os.listdir(path)) / 38)*100)
    print(num)
    gauge = Gauge("作业上交情况")
    gauge.add("", "完成率", num)
    return gauge

        #统计日志
def write_txt():
    l_dir = os.listdir(path)
    with open(log_path + '作业统计表.txt','w') as f:
        for line in l_dir:
            f.write(line + "\n")
    

#       展示dict{}
def dispaly_people():
    ll = os.listdir(path)
    people = {}
    for one in ll:
        if(one != '作业统计表.txt'):
            std_num = one.split('-')[0]
            people[std_num] = (one.split('-')[1],one.split('-')[2])
    return people
