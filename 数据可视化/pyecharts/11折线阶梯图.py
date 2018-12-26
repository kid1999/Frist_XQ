from pyecharts import Line
line = Line("折线图——阶梯实例",'hello world')
attr = ["{}".format(n) for n in range(1,7)]
v1 = [5, 20, 36, 10, 75, 90]
v2 = [10, 25, 8, 60, 20, 80]
#                         阶梯显示     标注节点信息        
line.add("one",attr,v1,is_step=True,is_label_show=True,mark_point=["average"])
line.add("two",attr,v2,is_smooth=True,mark_line=["min","max"])
line.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\11.html')