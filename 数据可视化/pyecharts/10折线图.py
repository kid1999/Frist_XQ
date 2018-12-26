from pyecharts import Line

line = Line("折线图实例")
attr = ["{}".format(n) for n in range(1,7)]
v1 = [5,20,36,10,75,90]
v2 = [10,25,8,60,20,80]

line.add("one",attr,v1,mark_point=["average"])
line.add("two",attr,v2,is_smooth=True,mark_line={"min","max"})#is_smooth=True平滑的曲线
line.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\10.html')