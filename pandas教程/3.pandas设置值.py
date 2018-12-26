import numpy as np
import pandas as pd

dates = pd.date_range('20180724',periods=6)
df = pd.DataFrame(np.arange(24).reshape(6,4),index=dates,columns=['A','B','C','D'])

print(df)

# df.iloc[0,1] = 111
# df.loc['20180724','C'] = 222                        #使用loc可以用索引定位

# df[df.A>4] = 0      #改变df
# df.A[df.A>4] = 1  #改变A列

# df['F'] = np.nan    #增加一列F
df['F'] = pd.Series([1,2,3,4,5,6],index=pd.date_range('20180724',periods=6))  #对应的添加一列数据
print(df)










