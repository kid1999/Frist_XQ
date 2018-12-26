import numpy as np
import pandas as pd


# #第一个例子 (横坐标相同)
# df1 = pd.DataFrame(np.zeros((3,4)),columns=['a','b','c','d'])
# df2 = pd.DataFrame(np.ones((3,4)),columns=['a','b','c','d'])
# df3 = pd.DataFrame(np.ones((3,4))*2,columns=['a','b','c','d'])
# print(df1)
# print(df2)
# print(df3)

# #上下合并
# res = pd.concat([df1,df2,df3],axis=0,ignore_index=True)  #忽略index纵坐标,重新排序
# print(res)


#第二个例子  (横纵坐标都不同)
df1 = pd.DataFrame(np.zeros((3,4)),columns=['a','b','c','d'],index=[1,2,3])
df2 = pd.DataFrame(np.ones((3,4)),columns=['b','c','d','e'],index=[2,3,4])
print(df1)
print(df2)
# res = pd.concat([df1,df2],join='inner',ignore_index=True)  #join默认使用outer模式,求并集,不存在的用nan填充  inner,求交集
res = pd.concat([df1,df2],axis=1,join_axes=[df1.index])   #join_axes 选择需要处理的行index
print(res)


#第三个例子:  append添加到末尾
# df1 = pd.DataFrame(np.zeros((3,4)),columns=['a','b','c','d'])
# df2 = pd.DataFrame(np.ones((3,4)),columns=['a','b','c','d'])
# df3 = pd.DataFrame(np.ones((3,4)),columns=['a','b','c','d'])

# # res = df1.append([df2,df3],ignore_index=True)  #全部加起来
# s1 = pd.Series([1,2,3,4],index=['a','b','c','d'])
# res = df1.append(s1,ignore_index=True)
# print(res)










