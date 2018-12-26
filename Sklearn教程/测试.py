from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier as knn  #knn模型
from sklearn.svm import SVC                                #svc模型
from sklearn.cross_validation import train_test_split
from sklearn import preprocessing                         #正规化


#加载数据:
load_data = datasets.load_digits()
x = load_data.data     #一维数组表示8*8的图片
y = load_data.target   #目标十个数字的识别


x = preprocessing.scale(x)  #正规化数据


x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.1)  #划分训练集


#使用knn模型:
model = knn()
model.fit(x_train,y_train)
y_predict = model.predict(x_test)  #knn的预测
#精确度:
s = sum(y_predict == y_test) / len(y_test)
print('精确度',s)


#使用svc模型:
# clf = SVC()
# clf.fit(x_train, y_train)
# y_predict = clf.predict(x_test)

# #精确度:
# s = sum(y_predict == y_test) / len(y_test)
# print('精确度',s)
