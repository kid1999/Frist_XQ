import numpy as np
from sklearn import datasets                           #自带的通用练习数据库
from sklearn.cross_validation import train_test_split  #划分训练集与测试集
from sklearn.neighbors import KNeighborsClassifier     #k近邻模型

iris = datasets.load_iris()
iris_X = iris.data
iris_y = iris.target

# print(iris_X)    #花的属性
# print(iris_y)    #花的类别

#将数据分开, 数据分为训练和测试,测试的比例占0.3
X_train,X_test,y_train,y_test = train_test_split(iris_X,iris_y,test_size=0.3)

# print(y_train)

#开始训练
knn = KNeighborsClassifier()
knn.fit(X_train,y_train)
#调试结果
print(knn.predict(X_test))
print(y_test)
