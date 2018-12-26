import numpy as np
import pandas as pd

dates = pd.date_range('20180724',periods=6)
df = pd.DataFrame(np.arange(24).reshape(6,4),index=dates,columns=['A','B','C','D'])

print(df)

#开始选择
print(df['A'],df.A)  #选择某序列
print(df[0:3],df['20180724':'20180726'])  #切片选择0:3行的数据  #切片选择序列()的数据




#select by label:                                    loc [ ] 纯标签筛选
print(df.loc['20180724'])   #使用loc后缀更具体的选取
print(df.loc['20180724',['A','B']])  #选择具体的数据

#selec by position:                                  iloc[ ]纯序列筛选   
print(df.iloc[[1,3,5],1:3])  #使用数字序号索引筛选

# mixed selection:                                    ix  [ ]   混合筛选
print(df.ix[:3,['A','C']])

#Boolean indexing:                                   布尔值筛选
print(df[df.A>8])  #在A中对比,大于8的数据








