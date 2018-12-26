from pyecharts import Radar
schema =[("语文",100),("数学",100),("英语",100),("物理",100),("化学",100),("生物",100)]
v1 = [[88,92,72,66,75,82]]
v2 = [[0,0,0,0,0,0]]

rader = Radar("one与two对比")
rader.config(schema)
rader.add("one",v1,is_splitLine=True,label_color=["blue"],is_axisline_show=True)

rader.add("two",v2,label_color=["red"],is_area_show=False)

rader.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\15.html')