import pandas as  pd
import numpy as np
import matplotlib.pyplot as plt

#Series
# data = pd.Series(np.random.randn(1000))
# data = data.cumsum()

#DataFrame
data = pd.DataFrame(np.random.randn(1000,4),index=np.arange(1000),columns=list("ABCD"))
data = data.cumsum()
# print(data.head(5))   #输出矩阵前5个数据

# data.plot()
# plt.show()

#plot method
# 'bar':条形图，'hist','box'......

#散点图：
ax =data.plot.scatter(x='A',y='B',color='DarkBlue',label='Class')
data.plot.scatter(x='A',y='C',color='DarkGreen',label='Class2',ax=ax)
plt.show()