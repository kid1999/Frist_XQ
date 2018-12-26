import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets('MNIST_data', one_hot=True)  #准备MNIST库

#添加层
def add_layer(inputs,in_size,out_size,activation_function=None):
    Weight = tf.Variable(tf.random_normal([in_size,out_size])) #随机in,out的矩阵
    biases = tf.Variable(tf.zeros([1,out_size]) + 0.1)  #一列数组的biases
    Wx_plus_b = tf.matmul(inputs,Weight) + biases       #神经网络未激活的值

    if activation_function is None:
        outputs = Wx_plus_b
    else:
        outputs = activation_function(Wx_plus_b)
    return outputs


#计算准确度:
def compute_accuracy(v_xs, v_ys):
    global prediction
    y_pre = sess.run(prediction, feed_dict={xs: v_xs})
    correct_prediction = tf.equal(tf.argmax(y_pre,1), tf.argmax(v_ys,1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
    result = sess.run(accuracy, feed_dict={xs: v_xs, ys: v_ys})
    return result

#搭建网络:
xs = tf.placeholder(tf.float32,[None,784])  #输入像素元素为 28*28
ys = tf.placeholder(tf.float32,[None,10])  #输出数字共有10个

#搭建一个最简单的训练网络结构，只有输入层和输出层。
prediction =  add_layer(xs,784,10,activation_function=tf.nn.softmax) 

#loss函数选用交叉熵函数。交叉熵用来衡量预测值和真实值的相似程度，如果完全相同，它们的交叉熵等于零。
loss = tf.reduce_mean(-tf.reduce_sum(ys*tf.log(prediction),reduction_indices=[1]))
#Train方法（最优化算法）采用梯度下降法。
train_step = tf.train.GradientDescentOptimizer(0.5).minimize(loss)

init = tf.global_variables_initializer()

sess = tf.Session()
sess.run(init)

#开始训练:

for i in range(1000):
    batch_xs,batch_ys = mnist.train.next_batch(100)  #每次调用这个方法只用100张照片进行训练
    sess.run(train_step,feed_dict={xs:batch_xs,ys:batch_ys})
    if i % 50==0:
        print('输出判断准确度:',compute_accuracy(
            mnist.test.images, mnist.test.labels))
             #   测试集的照片        标签




