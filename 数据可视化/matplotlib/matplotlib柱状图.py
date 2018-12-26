import matplotlib.pyplot as plt

#使用主题：
plt.style.use('ggplot')  #通常使用以下几种主题：ivethirtyeight，ggplot，dark_background，bmh

input_values = [1, 2, 3, 4, 5]
squares = [1,4,8,16,25]
#plt.bar(input_values, squares)  #普通柱状图
plt.barh(input_values, squares)  #水平柱状图
            #x轴数据  #y轴数据    

#设置图表标题 坐标轴 名称

plt.title('Month vs Area')  #标题

plt.xlabel('month')         #X轴名字

plt.ylabel('area')          #y轴名字

# 设置刻度标记的大小
plt.tick_params(axis='both', labelsize=14)   #设置刻度样式

plt.show()