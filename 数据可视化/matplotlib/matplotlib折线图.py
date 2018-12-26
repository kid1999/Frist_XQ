import matplotlib.pyplot as plt
#使用主题：
plt.style.use('ggplot')  #通常使用以下几种主题：ivethirtyeight，ggplot，dark_background，bmh

input_values = [1, 2, 3, 4, 5]
squares = [1,4,8,16,25]
plt.plot(input_values,squares,linewidth=5)   
             #x轴数据  #y轴数据    # 设置绘制的线条的粗细  

#设置图表标题 坐标轴 名称
plt.title("Square Numbers", fontsize=24)    # 图表的标题
plt.xlabel("Value", fontsize=14)            
plt.ylabel("Square of Value", fontsize=14)

# 设置刻度标记的大小
plt.tick_params(axis='both', labelsize=14)   #设置刻度样式

plt.show()