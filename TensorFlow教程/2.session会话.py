import tensorflow as tf

#给定俩个矩阵：矩阵相乘 （tensorflow定义的矩阵）
matrix1 = tf.constant([[3,3]])
matrix2 = tf.constant([[2],
                       [2]])

product = tf.matmul(matrix1,matrix2)  #矩阵相乘

#  method1
# sess = tf.Session()
# result = sess.run(product)

# print(result)
# sess.close()

# method2
with tf.Session() as sess:
    result = sess.run(product)
    print(result)
    









