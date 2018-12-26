from pyecharts import Pie

attr = ['game','唠嗑','新闻','学习','玩手机']
value = [0.1,3,2,5,5]
pie = Pie("饼图实例/emmm")
pie.add("饼干",attr,value,is_label_show=True)
pie.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\14.html')