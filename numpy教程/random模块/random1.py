import numpy as np

# 1.numpy.random.random()　生成随机浮点数
print(np.random.random())
print(np.random.random(size=(3, 2)))   #(3,2)的随机浮点数


# 2.numpy.random.randint()　产生随机整数
print(np.random.randint(8))               #一个整数(0-8)
print (np.random.randint(5, size=3))      #三个整数(0-5)
print (np.random.randint(6, size=(3,2)))  #(3,2)个整数(0-6)


# 3.numpy.random.normal() 　高斯分布随机数
print(np.random.normal(loc=0.0, scale=1, size=(2, 3)))  #loc：均值，scale：标准差，size：抽取样本的size


# 4.numpy.random.randn()　标准正态分布随机数
print (np.random.randn(4, 2))
print (np.random.randn(4, 2, 3))


# 5.numpy.random.rand()　生成[0, 1)间随机数
print (np.random.rand(2,3))  #(2,3)的0/1随机数

# 6.numpy.random.shuffle()　随机打乱序列
list = list(range(0, 8, 1))
print(np.random.shuffle(list))