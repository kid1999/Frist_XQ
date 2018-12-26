from pyecharts import Polar
radius = ["周一","周二",'周三','周四','周五']
polar = Polar("极坐标系堆叠图实例")
#环状累加
# polar.add("A",[1,2,3,4,1],radius_data=radius,type='barRadius',is_stack=True)
# polar.add("B",[2,4,3,1,2],radius_data=radius,type='barRadius',is_stack=True)
# polar.add("C",[1,4,2,3,4],radius_data=radius,type='barRadius',is_stack=True)

#柱状
polar.add("A", [1, 2, 3, 4, 3 ], radius_data=radius, type='barAngle', is_stack=True)
polar.add("B", [2, 4, 6, 1, 2], radius_data=radius, type='barAngle', is_stack=True)
polar.add("C", [1, 2, 3, 4, 1 ], radius_data=radius, type='barAngle', is_stack=True)

polar.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\19.html')
