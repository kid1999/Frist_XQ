import tensorflow as tf
import numpy as np

#添加层
def add_layer(inputs,in_size,out_size,activation_function=None):
    with tf.name_scope('layer'):
        with tf.name_scope('weight'):
            Weight = tf.Variable(tf.random_normal([in_size,out_size]),name='w') #随机in,out的矩阵
        with tf.name_scope('biases'):
            biases = tf.Variable(tf.zeros([1,out_size]) + 0.1,name='b')  #一列数组的biases
        with tf.name_scope('Wx_plus_b'):
            Wx_plus_b = tf.matmul(inputs,Weight) + biases       #神经网络未激活的值

        if activation_function is None:
            outputs = Wx_plus_b
        else:
            outputs = activation_function(Wx_plus_b)
        return outputs



# 1.训练的数据
x_data = np.linspace(-1,1,300)[:, np.newaxis]
noise = np.random.normal(0, 0.05, x_data.shape)
y_data = np.square(x_data) - 0.5 + noise

# 2.定义节点准备接收数据
with tf.name_scope('inputs'):
    xs = tf.placeholder(tf.float32, [None, 1],name='x_input')
    ys = tf.placeholder(tf.float32, [None, 1],name='y_input')

#定义神经层:  输入一个 隐藏层10个 输出1个的神经网络
#定义隐藏层        用tf自带的激励函数  relu
l1 = add_layer(xs, 1, 10, activation_function=tf.nn.relu)

#定义预测层
prediction = add_layer(l1, 10, 1, activation_function=None)

#计算预测值prediction和真实值的误差，对二者差的平方求和再取平均。
with tf.name_scope('loss'):
    loss = tf.reduce_mean(tf.reduce_sum(tf.square(ys - prediction),reduction_indices=[1]))

#调用优化器:   
with tf.name_scope('train'): 
    train_step = tf.train.GradientDescentOptimizer(0.1).minimize(loss) 

#初始化变量
init = tf.global_variables_initializer()

sess = tf.Session()
writer = tf.summary.FileWriter('logs/',sess.graph)             #将产生的计算图储存在...下
sess.run(init)

#训练
for i in range(1000):
    sess.run(train_step,feed_dict={xs: x_data, ys: y_data})
    if i % 50 == 0:
        result = sess.run(loss,feed_dict={xs:x_data,ys:y_data})
        print(result)













