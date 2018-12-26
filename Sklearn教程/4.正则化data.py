
# 1.简单的示范正规化      数据分布广泛

# from sklearn import preprocessing #正规化
# import numpy as np

# a = np.array([[10,2.7,3.6],
#             [-100,5,-2],
#             [120,20,40]],dtype = np.float64)

# print(a)
# print(preprocessing.scale(a))



# 2.一个正规化与未正规化的对比：

from sklearn import preprocessing    #预处理
import numpy as np
# 将资料分割成train与test的模块
from sklearn.model_selection import train_test_split
# 生成适合做classification资料的模块（分类）
from sklearn.datasets.samples_generator import make_classification 
# 支持向量机中的支持向量分类器
from sklearn.svm import SVC 
# 可视化数据的模块
import matplotlib.pyplot as plt 

#生成具有2种属性的300笔数据
X, y = make_classification(
    n_samples=300, n_features=2,  #三百个样本,2个特征
    n_redundant=0, n_informative=2, 
    random_state=22, n_clusters_per_class=1, 
    scale=100)
#可视化数据
plt.scatter(X[:, 0], X[:, 1], c=y)  #两种样本分布
plt.show()



#没有正规化的训练;
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
clf = SVC()
clf.fit(X_train, y_train)
print('没有正规化的训练精度:',clf.score(X_test, y_test))


#正规化的训练
X = preprocessing.scale(X)  #正规化
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
clf = SVC()
clf.fit(X_train, y_train)
print('正规化后的训练精度:',clf.score(X_test, y_test))











