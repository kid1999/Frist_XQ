import numpy as np
array = np.array([[1,2,3],[4,5,6]])
print(array)
print('行索引:',array[1])
print('列索引:',array[:,1])
print('行列索引:',array[1][1])
print('另一种写法:',array[1,1])

for row in array:
    print(row)     #迭代每一行

for column in array.T:
    print(column)  #迭代每一列

print(array.flatten()) #返回一个序列
for item in array.flat:#迭代每一个值
    print(item)

