import numpy as np
array = np.array([[1,2,3],[4,5,6]])
print(array)
print('最小值索引:',np.argmin(array))
print('最大值索引:',np.argmax(array))
print('平均值:',np.mean(array))
#扩展:
print('平均值的属性:',np.mean(array,axis=0))      #axis=0对列进行平均值计算,axis=1对行进行平均值计算
print('中位数:',np.median(array))
print('累加:',np.cumsum(array))                  #输出一维矩阵 
print('累差:',np.diff(array))                    #输出二维矩阵
print('得到非零数的位置:',np.nonzero(array))      #输出行矩阵,列矩阵
print('排序:',np.sort(array))                    #逐行排序
print('矩阵转置:',np.transpose(array))           #行列转换
print('矩阵运算中的转置:',(array.T).dot(array))
print('滤波:',np.clip(array,2,5))                #最小值为2,最大值5 
