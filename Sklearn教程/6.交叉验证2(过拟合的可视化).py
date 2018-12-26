from sklearn.learning_curve import learning_curve #学习曲线模块    >> test/train学习效率的体现
from sklearn.datasets import load_digits          #digits手写体的数字,数据集
from sklearn.svm import SVC                       #向量机支持模型
import matplotlib.pyplot as plt                   #可视化模块
import numpy as np

#加载数据:
digits = load_digits()
X = digits.data
y = digits.target


# learning_curve只能看到 这个环境下test,train的误差变化
train_sizes, train_loss, test_loss = learning_curve(
    SVC(gamma=0.001), X, y, cv=10, scoring='mean_squared_error',  #svc模型, 平均方差误差计算
    train_sizes=[0.1, 0.25, 0.5, 0.75, 1])   #样本由小到大分成5轮检视学习曲线(10%, 25%, 50%, 75%, 100%)

#平均每一轮所得到的平均方差(共5轮，分别为样本10%、25%、50%、75%、100%)
train_loss_mean = -np.mean(train_loss, axis=1)
test_loss_mean = -np.mean(test_loss, axis=1)

# 可视化图形:

plt.plot(train_sizes, train_loss_mean, 'o-', color="r",
         label="Training")
plt.plot(train_sizes, test_loss_mean, 'o-', color="g",
        label="Cross-validation")

plt.xlabel("Training examples")
plt.ylabel("Loss")
plt.legend(loc="best")
plt.show()