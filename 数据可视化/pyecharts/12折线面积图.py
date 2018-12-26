from pyecharts import Line
line = Line("折线图--面积实例",'hello')

#data
attr = ["{}".format(n) for n in range(1,7)]
v1 = [5, 20, 36, 10, 75, 90]
v2 = [10, 25, 8, 60, 20, 80]

#                           填充                    不透明性                    填充颜色       节点标注
line.add("one",attr,v1,is_fill=True,line_opacity=0.2,area_opacity=0.4,area_color='yellow',is_label_show=True)
                                                                                            #平滑曲线
line.add("two",attr,v2,is_fill=True,line_opacity=0.8,area_opacity=0.2,area_color='green',is_smooth=True)

line.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\12.html')