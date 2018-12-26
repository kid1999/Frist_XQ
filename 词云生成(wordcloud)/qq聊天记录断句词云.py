import re
from jieba import analyse
from snownlp import SnowNLP
import pickle   
import jieba_fast as jieba  
import matplotlib.pyplot as plt  
from wordcloud import WordCloud, STOPWORDS, ImageColorGenerator 


#TF_IDF算法:
tfidf = analyse.extract_tags
#TextRANK算法:
#textrank = analyse.extract_tags

#定义单句关键词分析:


def keyword_cloud(text): 
    backgroud_Image = plt.imread(r'C:\Users\Administrator\Desktop\词云生成(wordcloud)\timg.jpg')          #背景图片
    print('加载图片成功！')  
    '''''设置词云样式'''  
    wc = WordCloud(  
        background_color='white',# 设置背景颜色 (画布颜色)
        height=1200,  #蒙版的长宽
        width=2000, 
        mask=backgroud_Image,# 设置背景图片     (图片蒙版)
        font_path='C:\Windows\Fonts\STZHONGS.TTF',  # 选择字体  
        max_words=500, # 设置最大显示的字数  
        stopwords=STOPWORDS,# 设置停用词  
        max_font_size=150,# 设置字体最大值 
        #min_font_size=4,# 设置字体最小值 
        random_state=30,# 设置有多少种随机生成状态，即有多少种配色方案  
        scale = 1          #画布放大比例
    )  
    wc.generate_from_text(text)  
    print('开始加载文本')  
    #改变字体颜色  
    img_colors = ImageColorGenerator(backgroud_Image)         
    #字体颜色为背景图片的颜色  
    wc.recolor(color_func=img_colors)  
    # 显示词云图  
    plt.imshow(wc)  
    # 是否显示x轴、y轴下标  
    plt.axis('off')  
    plt.show()  #显示  
    wc.to_file(r'')   #保存 
    print('生成词云成功!')





def get_guanjianzi(txt):
    guanjianzi = tfidf(txt)
    for keyword in guanjianzi:
        print('本句关键词%s'%keyword)
        keywords = ' '.join(keyword)





keywords = ''
text = open(r'C:\Users\Administrator\Desktop\qq爬虫\新建文件夹\喻翠(1325966241).txt','r',encoding='utf-8', errors='ignore').read()
texts = re.findall('喻翠\n(.*?)\n',text)
for txt in texts:
    if len(txt)!=0:
        get_guanjianzi(txt)
print(keywords)
keyword_cloud(keywords)




 