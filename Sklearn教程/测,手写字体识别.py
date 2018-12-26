from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier as knn
from sklearn.cross_validation import train_test_split

    

#加载数据:
load_data = datasets.load_digits()
x = load_data.data     #一维数组表示8*8的图片
y = load_data.target   #目标十个数字的识别

x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2)  #划分训练集

# print(x.shape)  #数据为(1797,64)
# print(y.shape)  #    (1794,)

#加载模型,训练
model = knn()
model.fit(x_train,y_train)

#测试
y_predict = model.predict(x_test)
print(len(y_test))

#精确度:
s = sum(y_predict == y_test) / len(y_test)
print('精确度',s)
