from pyecharts import Bar,Scatter3D,Page

page = Page()

#数据
attr = ["java","html","python",'js']
v1 = [5,20,36,10]
v2 = [10,25,8,60]

#bar柱状图
bar = Bar("柱状图数据堆叠实例")
bar.add("A班",attr,v1,is_stack=True)#is_stack表示是否对叠在一起
bar.add("B班",attr,v2,is_stack=True)

page.add(bar)

#Scatter3D 图
import random
data = [[random.randint(0,100),random.randint(0,100),random.randint(0,100)] for _ in range(80)]
range_color = ['#313695', '#4575b4', '#74add1', '#abd9e9']

scatter3D = Scatter3D("3D散点示意图")
scatter3D.add("",data,is_visualmap=True,visual_range_color=range_color)
page.add(scatter3D)
page.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\3.html')