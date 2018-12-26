import numpy as np
#定义属性dtype
#定义形状reshape
#定义初始矩阵得值 empty/zeros/ones  方法((2,3))
#生成矩阵array()
#生成数列arange()
#生成线段linespace()


array = np.array([2,23,4],dtype = np.int)
print(array)
print(array.dtype)                #返回定义array的属性

array1 = np.array([[2,23,4],[4,5,6]])     #定义二维矩阵 用[]包括
print(array1)


array2 = np.zeros((3,4))   #生成三排四列 值为0的矩阵
print(array2)

array3 = np.ones((3,4))    # 值为1
print(array3)
 
a = np.arange(0,10,2)   #生成一个0-10 步长为2的数组
print(a)

a1 = np.arange(12).reshape((3,4))  #生成0-12的 形状为3,4的矩阵
print(a1)

a2 = np.linspace(1,10,5)    #生成1-10的 分5段 的数列
print(a2)
