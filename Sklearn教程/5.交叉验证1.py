import numpy as np
from sklearn import datasets                           #自带的通用练习数据库
from sklearn.cross_validation import train_test_split  #划分训练集与测试集
from sklearn.neighbors import KNeighborsClassifier     #k近邻模型
from sklearn.cross_validation import cross_val_score  # K折交叉验证模块  >>test精度得分
import matplotlib.pyplot as plt                      #可视化模块

#数据集:
iris = datasets.load_iris()
X = iris.data
y = iris.target

# 1.普通操作:

#将数据分开, 数据分为训练和测试,测试的比例占0.3
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3)

#开始训练
knn = KNeighborsClassifier()
knn.fit(X_train,y_train)


# 1.普通操作:
# #调试结果
# print(knn.score(X_test,y_test)) #训练得分



# 2.交叉验证:
# from sklearn.cross_validation import cross_val_score # K折交叉验证模块

# #使用K折交叉验证模块
# scores = cross_val_score(knn, X, y, cv=5, scoring='accuracy')   #分数据时采用随机分5次 五点求平均减小误差
# #将5次的预测准确率打印出
# print(scores)
# # 将5次的预测准确平均率打印出
# print(scores.mean())



#有上面的基础后:

# 3.准确率(accuracy)会用于判断分类(Classification)模型的好坏。
import matplotlib.pyplot as plt #可视化模块

#建立测试参数集
k_range = range(1, 31)  #参数取值范围为1-30
k_scores = []           

#藉由迭代的方式来计算不同参数对模型的影响，并返回交叉验证后的平均准确率
for k in k_range:
    knn = KNeighborsClassifier(n_neighbors=k)   #本次是 调整knn的近邻参数k

                                                #两种计算误差的方法:
    scores = cross_val_score(knn, X, y, cv=10, scoring='accuracy')         #一般来说准确率(accuracy)会用于判断分类(Classification)模型的好坏。
    # loss = -cross_val_score(knn, X, y, cv=10, scoring='mean_squared_error')#一般来说平均方差(Mean squared error)会用于判断回归(Regression)模型的好坏。
    k_scores.append(scores.mean())

#可视化数据
plt.plot(k_range, k_scores)
plt.xlabel('Value of K for KNN')
plt.ylabel('Cross-Validated Accuracy')
plt.show()