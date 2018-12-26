import easygui as g 
import datetime
import xlwt,xlrd

# nowTime=datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')




# msg = "请填写一下信息"
# title = "仅限西区使用!!!"
# fieldNames = ["宿舍号","烧麦(1.5)","包子(1)","...."]
# fieldValues = []
# fieldValues = g.multenterbox(msg,title,fieldNames)
# print("您填写的资料如下:%s" %str(fieldValues))

# all = float(fieldValues[1])*1.5 + float(fieldValues[2])*1
# print(all)

# title = g.msgbox("总计:  "+ str(all) + "\n                                          订单时间: " + nowTime,title="总计:",ok_button="完成") 

# with open("C:\\test.txt","a") as f:
#     f.write(fieldValues[0] + "  ")
#     f.write("烧麦: " + fieldValues[1] + "  ")
#     f.write("包子: " + fieldValues[2] + "  ")
#     f.write(nowTime+ "\n")
# f.close()


#创建excel文件  ，并且写excel  
excel = xlwt.Workbook()                                     #建立excel工作空间     
sheet1 = excel.add_sheet('订餐统计')                      #创建sheet1，名字为小说统计  
sheet1.write(0,0,'寝室号')                                  #写入的第一行，第1列写值    
sheet1.write(0,1,'烧麦')                                  #写入的第一行，第2列写值
sheet1.write(0,2,'包子') 
sheet1.write(0,3,'订餐时间')        



#读取
with open("C:\\test.txt","r") as f:
    lines = f.readlines()
    i = 1
    for line in lines:
        value = line.split()  

        sheet1.write(i,0,value[0])
        sheet1.write(i,1,int(value[2]))
        sheet1.write(i,2,int(value[4]))
        sheet1.write(i,3,value[5] + " "+ value[6])
        i =i+1  


excel.save(r'c:\统计表.xls') #保存excel
print('写入完成.....')




