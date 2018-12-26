import numpy as np
a = np.arange(12).reshape(3,4)
print(a)

print(np.split(a,2,axis=1)) #等量 横向分割成2块
print(np.array_split(a,3,axis=1)) #不等量 横向分割成3块

#也可以用:
# print(np.vsplit(a,3)) #上下分成3行
# print(np.hsplit(a,2)) #左右分成2列