import tensorflow as tf
import numpy as np

#create data
x_data = np.random.rand(100).astype(np.float32)
y_data = x_data*0.1+0.3


#create tensorflow structure   搭建模型
#weight权重  的参数变量     生成随机数列    一维   范围(-1,1) 
Weight = tf.Variable(tf.random_uniform([1],-1.0,1.0))   
#biases偏差  的参数变量      0
biases = tf.Variable(tf.zeros([1]))
#定义函数模型
y = Weight*x_data + biases


#loss函数（即最优化目标函数）   此处选用 算数平均值
loss = tf.reduce_mean(tf.square(y-y_data))


#反向传递修正误差:
# 梯度下降优化器,参数更新           学习效率
optimizer = tf.train.GradientDescentOptimizer(0.5)
# 将误差最小化
train = optimizer.minimize(loss)


init = tf.initialize_all_variables()    #初始化所有变量   使用结构


#  激活系统
sess = tf.Session()  #创建会话,  类似一个鼠标
# sess = tf.Session(config=tf.ConfigProto(log_device_placement=True))  #强制使用gpu
sess.run(init)   #  点击图标(初始化)

#进行两百次训练
for step in range(201):
    sess.run(train)
    if step % 20 ==0:
        print(step,sess.run(Weight),sess.run(biases))





