from pyecharts import Gauge
gauge = Gauge("仪表盘实例","hello world")
gauge.add("学习","进度",10.00)
gauge.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\9.html')