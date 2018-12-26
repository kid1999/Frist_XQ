from sklearn.learning_curve import validation_curve #validation_curve模块     >>train/test学习效率,随参数的变化
from sklearn.datasets import load_digits          #digits手写体的数字,数据集
from sklearn.svm import SVC                       #向量机支持模型
import matplotlib.pyplot as plt                   #可视化模块
import numpy as np

#加载数据:
digits = load_digits()
X = digits.data
y = digits.target

#建立model参数测试集
param_range = np.logspace(-6, -2.3, 5)  #选取5个log(-6到-2.3)的model的gamma变量

#使用validation_curve快速找出model参数对模型精度的影响   >>>看出过拟合,得到最优点(精度最高,也不过拟合)
train_loss, test_loss = validation_curve(
    SVC(), X, y, param_name='gamma', param_range=param_range, cv=10, scoring='mean_squared_error')

#平均每一轮所得到的平均方差
train_loss_mean = -np.mean(train_loss, axis=1)
test_loss_mean = -np.mean(test_loss, axis=1)

#可视化图形
plt.plot(param_range, train_loss_mean, 'o-', color="r",
         label="Training")
plt.plot(param_range, test_loss_mean, 'o-', color="g",
        label="Cross-validation")


plt.xlabel("gamma")
plt.ylabel("Loss")
plt.legend(loc="best")
plt.show()