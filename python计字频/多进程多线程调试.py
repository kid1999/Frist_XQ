#多线程实验版
import threading
import jieba_fast as jieba
import time
from collections import Counter
from multiprocessing import Pool


#cpu密集型:

def Cpu(i):
    return i*i*i*i*i*i*i*100000000

#io密集型:

def Io(i):
    with open(r'C:\Users\Administrator\Desktop\python计字频\测试文件.txt','a') as f:
        f.write('这是第%d个写入........'%i)
    f.close()


#多线程:
class MyThread(threading.Thread): # 这个类的一个实例就是代表了一个线程，然后通过重载这个类中的run方法（是run，不是start！！但start的动作确实就是调用run）来执行具体的操作。
    def __init__(self,arg):
        super(MyThread, self).__init__()#注意：一定要显式的调用父类的初始化函数。
        self.arg=arg

    def Io(self):
        with open(r'C:\Users\Administrator\Desktop\python计字频\测试文件.txt','a') as f:
            f.write('这是第%d个写入........'%self.arg)
        f.close()

for i in range(10000):
    t = MyThread(i)
    t.start()








