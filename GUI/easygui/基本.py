import easygui as g
import sys

#msgbox    是
# msg = g.msgbox("Hello Easy GUI")  #初始值   点击ok_button后结束任务
# title = g.msgbox("我一定要学会编程！",title="标题部分",image=r'C:\Users\Administrator\Desktop\百度人脸识别api\4.jpg',ok_button="加油") 


#ccbox()    是否
# if g.ccbox("亲爱的还玩吗?",choices=("还要玩！","算了吧/(ㄒoㄒ)/~~")):  #choice1 = True
#     g.msgbox("还是不玩了，快睡觉吧！")
# else:
#     sys.exit(0)


#buttombox()  选项
# r = g.buttonbox(msg="你喜欢下面哪种水果?",title="",choices=("西瓜","苹果","草莓"),image=r'C:\Users\Administrator\Desktop\百度人脸识别api\4.jpg')
# print(r)


#choicebox()  单选
# msg = "选择你喜欢的一种业余生活"
# choicess_list = ["看书","游泳","骑自行车","玩游戏"]
# reply = g.choicebox(msg,choices=choicess_list)
# print(reply)


#mutchoicebox() 不定项选
# r = g.multchoicebox(msg="请选择你爱吃哪些水果?",title="",choices=("西瓜","香蕉","苹果","梨"))
# print(r)


#enterbox()     输入框
# r = g.enterbox(msg="请说出此时你的心里话",title="心里悄悄话")
# print(r)


# interbox()   数字限定输入框
r= g.integerbox(msg="请输入您的得分",title="分数统计",lowerbound=0,upperbound=100)
print(r)

#fileopenbox()  选择文件
# path = g.fileopenbox()       #default="c:/fishc/*.py"
# print(path)

#filesavebox()  #选择文件保存路径
# r = g.filesavebox()
# print(r)

#捕获异常 exceptionbox()
# try:
#     print('I Love FishC.com!')
#     int('FISHC') # 这里会产生异常
# except:
#     g.exceptionbox()
