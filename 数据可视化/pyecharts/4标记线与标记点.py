from pyecharts import Bar

bar = Bar("hello world")
attr=["{}".format(n) for n in range(1,7)]
print(attr)
v1 = [5, 10, 36, 10, 75, 90]
v2 = [10, 25, 8, 60, 20, 80]
bar.add("bar1",attr,v1,mark_point=["average"])#对于charcter1标出其平均值
bar.add("bar2",attr,v2,mark_line=["min","max"])#对于charcter2标出其最大，最小
bar.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\4.html')

