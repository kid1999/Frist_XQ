from selenium import webdriver
from bs4 import BeautifulSoup
import time
driver = webdriver.Chrome()
driver.get("http://i.qq.com")

friend_qq = '1447250889'

#登录......
driver.switch_to.frame("login_frame")        #定位到浮动窗口
driver.find_element_by_id('img_out_1447250889').click()
time.sleep(1)
 # 让webdriver操纵当前页
driver.switch_to.default_content()



 # 跳到别人的空间: 
driver.get("http://user.qzone.qq.com/" + friend_qq)  #后缀  /311表示直接进入说说   /4进入相册
# 照片 class ='c-tx2 js-album-desc-a'
driver.find_element_by_id('QM_Profile_Photo_A').click()
driver.find_element_by_id('album-cover js-album-cover').click()



