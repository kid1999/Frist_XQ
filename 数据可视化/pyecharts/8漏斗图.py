from pyecharts import Funnel
#选项
attr = ["美女",'房子','车子','事业','家人','娱乐','数码产品']
#权重
value = [150,100,80,120,140,90,70]
#新建一个漏斗图
funnel = Funnel("男人心漏斗图")

#                  数据 权重     边缘标签           中间标签
funnel.add("因素",attr,value,is_label_show=True,label_pos="inside",label_text_color="#fff")
funnel.render(r'C:\Users\Administrator\Desktop\数据可视化\pyecharts\html\8.html')