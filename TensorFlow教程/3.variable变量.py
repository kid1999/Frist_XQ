import tensorflow as tf

#定义变量：
state = tf.Variable(0,name='counter')
# print(state)
#设置常量：
one = tf.constant(1)

#加法：
new_value = tf.add(state , one)
# 赋值，state=new——value
update = tf.assign(state,new_value)

init = tf.global_variables_initializer() #定义了变量就要用这个初始变量

with tf.Session() as sess:
    sess.run(init)
    for _ in range(3):
        sess.run(update)
        print(sess.run(state))



    









