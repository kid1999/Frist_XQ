import numpy as np
import pandas as pd

dates = pd.date_range('20180724',periods=6)
df = pd.DataFrame(np.arange(24).reshape(6,4),index=dates,columns=['A','B','C','D'])

df.iloc[0,1] = np.nan   #假设丢失数据
df.iloc[1,2] = np.nan

#打印创造的矩阵: 
print(df)

print(df.dropna(axis=0,how='any'))      #丢掉有丢失数据的行/列    how='all'全部错误才丢掉

print(df.fillna(value = 0))             #填入丢失的数据 为0

print(df.isnull())                     #返回是否丢失数据的矩阵
print(np.any(df.isnull()) == True)     #返回是否丢失数据










