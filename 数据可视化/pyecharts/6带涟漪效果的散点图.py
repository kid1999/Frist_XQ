from pyecharts import  EffectScatter

#数据
v1=[10,20,30,40,50,60]
v2=[10,20,30,40,50,60]

es = EffectScatter("动态散点演示")
es.add("散点图",v1,v2)
es.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\6.html')