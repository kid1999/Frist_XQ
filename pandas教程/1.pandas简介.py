import numpy as np
import pandas as pd

#Series  DataFrame  DataFrame 的一些简单运用


s = pd.Series([1,3,6,np.nan,44,1])  #生成一个有序号的一维数组
print(s)


dates = pd.date_range('20180723',periods=6)   #顺序生成6个时间的一维数组
print(dates)



df = pd.DataFrame(np.random.randn(6,4),index=dates,columns=['a','b','c','d'])
#       二维矩阵        随机生成          行索引      列索引
print(df)

#DataFrame 的矩阵 可以用dict生成,也可以用np导入:

df1 = pd.DataFrame(np.arange(12).reshape((3,4)))#不带索引参数时  默认数字索引
print(df1)

df2 = pd.DataFrame({'A':[1,2,3],'B':pd.Series([1,3,np.nan]),'C':np.arange(3)})  #A,B,C对应一列
print(df2)


print(df2.index)  #行名字
print(df2.columns)  #列名字
print(df2.values)   #矩阵内容
print(df2.describe()) #describe()  数学运算描述
# print(df2.T)   #矩阵转置
print(df2.sort_index(axis=0,ascending=False))  #axis = 1 对横坐标索引进行排序,反序
print(df2.sort_values(by='A'))  #对某索引进行排序

