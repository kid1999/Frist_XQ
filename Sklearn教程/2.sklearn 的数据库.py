from sklearn import datasets
from sklearn.linear_model import LinearRegression  #线性回归模型
import matplotlib.pyplot as plt

#调用数据库的真实数据
loaded_data =  datasets.load_boston()
data_x = loaded_data.data                 #数据
data_y = loaded_data.target               #目标

#建模训练
model = LinearRegression()             #线性回归分析模型
model.fit(data_x,data_y)               #加载数据进模型

#对比
print(model.predict(data_x[:4,:]))    #只用四个样本进行对比 (1796,64)
print(data_y[:4])

#减小误差:
# 不同的model 参数 改变data的处理方式


  #  创建一个 回归分析案例         100个样本     1个特征      一个目标    噪声为1
x,y = datasets.make_regression(n_samples=100,n_features=1,n_targets=1,noise=10)
plt.scatter(x,y)     #画出散点图
plt.show()