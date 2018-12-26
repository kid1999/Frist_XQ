import sys 
from hdfs.client import Client


#关于python操作hdfs的方法可以查看:
#https://blog.csdn.net/gamer_gyt/article/details/52446757




# classhdfs.client.Client(url, root=None, proxy=None, timeout=None, session=None)
# url：ip：端口  root：制定的hdfs根目录  proxy：制定登陆的用户身份  timeout：设置的超时时间

#设置连接
client = Client("http://192.168.56.20:50070",root="/",session=False)



# list——获取指定路径的子目录信息
# print(client.list("/"))

# status——获取路径的具体信息
# print(client.status("/", strict=True))

# makedirs——创建目录
# print(client.makedirs("/hello"))

# rename—重命名
# print(client.rename("/hello","/helloWorld"))

# delete—删除
# print(client.delete("helloWorld"))

# upload——上传数据
# client.upload("/",r"C:\Users\Administrator\Desktop\斗破\斗破苍穹.txt")

# download——下载
# client.download("/斗破苍穹.txt",r"C:\Users\Administrator\Desktop")

# read——读取文件
# with client.read("/斗破苍穹.txt",encoding='GBK') as f:
#     print(f.read())


print(client.list("/"))







