import tensorflow as tf
import numpy as np

#用 tf.histogram_summary() 显示神经层的变化图表
def add_layer(inputs,in_size,out_size,n_layer,activation_function=None):
    layer_name='layer%s'%n_layer
    with tf.name_scope('layer'):
        with tf.name_scope('weights'):  #权重的变化
            Weight = tf.Variable(tf.random_normal([in_size,out_size]),name='W') 
            tf.summary.histogram(layer_name+'/weights',Weight)  

        with tf.name_scope('biases'):  #置差的变化
            biases = tf.Variable(tf.zeros([1,out_size]) + 0.1)
            tf.summary.histogram(layer_name+'/biases',biases)

    with tf.name_scope('Wx_plus_b'):  #计算结果的变化
        Wx_plus_b = tf.matmul(inputs,Weight) + biases       
        if activation_function is None:
            outputs = Wx_plus_b
        else:
            outputs = activation_function(Wx_plus_b)

        tf.summary.histogram(layer_name + '/outputs', outputs)          
        return outputs



# 1.训练的数据
x_data = np.linspace(-1,1,300)[:, np.newaxis]
noise = np.random.normal(0, 0.05, x_data.shape)
y_data = np.square(x_data) - 0.5 + noise

# 2.定义节点准备接收数据 
xs = tf.placeholder(tf.float32, [None, 1])
ys = tf.placeholder(tf.float32, [None, 1])

#3.创建两层神经网络
l1 = add_layer(xs, 1, 10,1, activation_function=tf.nn.relu)
prediction = add_layer(l1, 10, 1,2, activation_function=None)

#4.用tf.scalar_summary() 设置loss的变化图
with tf.name_scope('loss'):
    loss = tf.reduce_mean(tf.reduce_sum(tf.square(ys - prediction),reduction_indices=[1]))
    tf.summary.scalar('loss',loss)



#5.调用优化器:
train_step = tf.train.GradientDescentOptimizer(0.1).minimize(loss)  

#6.初始化变量
init = tf.global_variables_initializer()
sess = tf.Session()

#7.打包所以训练图
merged = tf.summary.merge_all()                    #总结所有的训练图
writer = tf.summary.FileWriter('logs/',sess.graph) #储存
 

#8.训练
sess.run(init)
for i in range(1000):
    sess.run(train_step,feed_dict={xs: x_data, ys: y_data})
    if i % 50 == 0:
        result = sess.run(merged,feed_dict={xs:x_data,ys:y_data})   #运行合并得到数据
        writer.add_summary(result,i)                                #储存数据













