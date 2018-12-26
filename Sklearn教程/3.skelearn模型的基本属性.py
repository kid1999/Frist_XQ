from sklearn import datasets
from sklearn.linear_model import LinearRegression  #线性回归模型

#调用数据库的真实数据
loaded_data =  datasets.load_boston()
data_x = loaded_data.data                 #数据
data_y = loaded_data.target               #目标

#建模训练
model = LinearRegression()             #线性回归分析模型
model.fit(data_x,data_y)               #加载数据进模型

# model.fit 和 model.predict 就属于 Model 的功能，用来训练模型，用训练好的模型预测。

#详解model的属性和功能:
print(model.coef_)   #样本各个属性所对应的权重w
print(model.intercept_) #模型总的的偏置量biases

print(model.get_params) #取出之前model定义的参数
print(model.score(data_x,data_y)) #对model的训练准确度进行打分,每个模型对应的打分方式不同









