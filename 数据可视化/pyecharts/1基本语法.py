from pyecharts import Bar
bar = Bar("我的第一个图表","这是副标题")

#添加数据   x标题     x数据                         y数据          添加更多功能
bar.add("班级",["计科本171","数应172","数应173"],[39,41,50],is_more_utils=True)
# bar.print_echarts_options()       #调试用 观看js代码

#生成文件
bar.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\1.html')