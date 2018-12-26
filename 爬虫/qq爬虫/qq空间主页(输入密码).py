from selenium import webdriver
import time
driver = webdriver.Chrome()
driver.get("http://i.qq.com")

friend_qq = '1447250889'


 # 定位到登录所在的frame
driver.switch_to.frame("login_frame")        #定位到浮动窗口

 # 自动点击账号登陆方式
driver.find_element_by_id("switcher_plogin").click()
 # 账号输入框输入已知qq账号
driver.find_element_by_id("u").send_keys('1447250889')
 # 密码框输入已知密码
driver.find_element_by_id("p").send_keys('5201314xyQYC')
 # 自动点击登陆按钮
driver.find_element_by_id("login_button").click()
 # 让webdriver操纵当前页
driver.switch_to.default_content()
 # 跳到说说的url, friend可以任意改成你想访问的空间，比如这边访问自己的qq空间
driver.get("http://user.qzone.qq.com/" + friend_qq )              #后缀 : /311是进入说说                

#处理意外弹窗:
try:
    #找到关闭按钮，关闭提示框
    button = driver.find_element_by_id("dialog_button_111").click()
except:
    pass
time.sleep(1)
# 照片 class ='c-tx2 js-album-desc-a'
driver.find_element_by_id('QM_Profile_Photo_A').click()
driver.find_element_by_id('album-cover js-album-cover').click()  