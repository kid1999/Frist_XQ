from pyecharts import Pie

attr = ["java",'python','c++','php']
v1 = [11,15,12,10]
v2 = [15,11,20,15]
pie = Pie("饼图-玫瑰图实例")

#                           图形位置      按百分比划分                      按半径取圆环
pie.add("A班",attr,v1, center=[25, 50],rosetype="radius",is_random=True,radius=[30, 75])

#                             图形位置     按面积划分
pie.add("B班",attr,v2, center=[75, 50],rosetype="area",is_legend_show=False,is_label_show=True)
pie.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\18.html')