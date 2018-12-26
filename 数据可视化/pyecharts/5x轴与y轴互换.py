from pyecharts import Bar
bar = Bar("x轴与y轴互换")
attr=["1","2","3","4","5","6"]
v1 = [5, 20, 36, 10, 75, 90]
v2 = [10, 25, 8, 60, 20, 80]
bar.add("one",attr,v1,mask_point=["average"])
bar.add("two",attr,v2,is_convert=True,mark_line=["min","max"])#is_convert=True 是否反向(放在最后一个信息上)
bar.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\5.html')