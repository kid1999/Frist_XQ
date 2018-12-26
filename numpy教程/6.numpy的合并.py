import numpy as np
a = np.array([1,1,1])
b = np.array([2,2,2])


# print(np.vstack((a,b)))  #上下合并
# print(np.hstack((a,b)))  #左右合并
# #添加一个维度:         #也可以直接reshape
# print(a.shape)
# print(a[:,np.newaxis])# 在纵向加一个维度
# print(a[np.newaxis,:])# 在横向加一个维度
# print(a[:,np.newaxis].shape)

#综合
a = np.array([1,1,1])[:,np.newaxis]  
b = np.array([2,2,2])[:,np.newaxis]  # 产生竖向矩阵
print(a)
print(b)
c = np.concatenate((a,b,a),axis=1)   #axis=1横向合并
print(c)
