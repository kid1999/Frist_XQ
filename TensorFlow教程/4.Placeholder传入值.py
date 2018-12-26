import tensorflow as tf


#            占位        给定类型    ,#[]给定结构
input1 = tf.placeholder(tf.float32)
input2 = tf.placeholder(tf.float32)

           #做乘法运算
output = tf.multiply(input1,input2)

with tf.Session() as sess:     #以dict形式传入参数
    print(sess.run(output,feed_dict={input1:[7],input2:[2]}))

    









