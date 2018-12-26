import thulac	


#thu1 = thulac.thulac()  #默认模式
#text = thu1.cut("我爱北京天安门", text=True)  #进行一句话分词
#print(text)


 #代码示例2
thu1 = thulac.thulac(seg_only=True)  #只进行分词，不进行词性标注
thu1.cut_f(r'C:\Users\Administrator\Desktop\python计字频\斗破苍穹1.txt', r'C:\Users\Administrator\Desktop\三种分词库的使用\清华库的分词.txt')  #对input.txt文件内容进行分词，输出到output.txt
print(thu1)

#方法备注：
python版接口参数
thulac(user_dict=None, model_path=None, T2S=False, seg_only=False, filt=False)初始化程序，进行自定义设置

user_dict           设置用户词典，用户词典中的词会被打上uw标签。词典中每一个词一行，UTF8编码
T2S                 默认False, 是否将句子从繁体转化为简体
seg_only            默认False, 时候只进行分词，不进行词性标注
filt                默认False, 是否使用过滤器去除一些没有意义的词语，例如“可以”。
model_path          设置模型文件所在文件夹，默认为models/
cut(文本, text=False) 对一句话进行分词

text                默认为False, 是否返回文本，不返回文本则返回一个二维数组([[word, tag]..]),tag_only模式下tag为空字符。
cut_f(输入文件, 输出文件) 对文件进行分词

run() 命令行交互式分词(屏幕输入、屏幕输出)