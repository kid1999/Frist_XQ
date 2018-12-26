from sklearn import svm
from sklearn import datasets

#简单建立与训练一个SVCModel
iris = datasets.load_iris()
X, y = iris.data, iris.target
clf = svm.SVC()
clf.fit(X,y)


#方法一  pickle    >> .pickle
# import pickle #pickle模块

# #保存Model(注:save文件夹要预先建立，否则会报错)
# with open(r'C:\Users\Administrator\Desktop\Sklearn教程\model\clf.pickle', 'wb') as f:
#     pickle.dump(clf, f)

# #读取Model
# with open(r'C:\Users\Administrator\Desktop\Sklearn教程\model\clf.pickle', 'rb') as f:
#     clf2 = pickle.load(f)
#     #测试读取后的Model
#     print(clf2.predict(X[0:100]))
#     print(y[:100])


#方法二   joblib  >> .pkl
from sklearn.externals import joblib #jbolib模块

#保存Model(注:save文件夹要预先建立，否则会报错)
joblib.dump(clf, r'C:\Users\Administrator\Desktop\Sklearn教程\model\clf.pkl')

#读取Model
clf3 = joblib.load(r'C:\Users\Administrator\Desktop\Sklearn教程\model\clf.pkl')

#测试读取后的Model
print(clf3.predict(X[0:1]))
