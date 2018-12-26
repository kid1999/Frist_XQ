# 要开始使用Kazoo，必须创建一个KazooClient对象并建立连接：
# 来自 kazoo.client  导入 KazooClient

from kazoo.client import KazooClient

zk = KazooClient(hosts='192.168.56.20:2181')
zk.start()

#创造节点与对应的值
# s1 = zk.create("/hello",b"helloworld")
# print(s1)

#得到节点值值
# s2 = zk.get("/hello")
# print(s2)

#删除节点
s3 = zk.delete("/hello")
print(s3)

#关闭连接
zk.stop()