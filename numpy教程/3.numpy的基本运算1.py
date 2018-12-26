import numpy as np

# #一维数组:
a = np.arange(4)
b = np.array([10,20,30,40])

# #必须是一一对应运算
# c = a+b 
# c = a*b     
# # c = b**a   #乘方运算
# # c = np.sin(a)  #三角函数运算

# print(a)
# print(a<3)    #布尔值返回判断结果
# print(b)
# print(c)
# print(np.dot(a,b))    #一维数组的dot ，np.dot([1,2,3],[4,5,6]) = 1*4 + 2*5 + 3*6  = 32


#二维矩阵:
a = np.arange(4).reshape((2,2))
b = np.array([[10,20],[30,40]])

c = a*b   #基础运算
c_dot = np.dot(a,b)   #二维矩阵的dot 

print(a)
print(b)
print(c)
print(c_dot)
