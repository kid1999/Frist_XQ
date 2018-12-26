import numpy as np
a = np.arange(4)
print(a)

#赋值:  b,c,d 完完全全一样,改变一个全部改变.
# b=a
# c=a
# d=b
# print(a,b,c,d)

#或者：
# f = a[:]

#copy :  b 只得到copy时的值,不会具有后续的关联性
b = a.copy() #deepcopy()

a[2] = 11
print(a[2],b[2])
