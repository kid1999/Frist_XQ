from selenium import webdriver
from time import sleep
driver = webdriver.Chrome()
driver.get('https://graph.qq.com/oauth2.0/show?which=Login&display=pc&response_type=code&client_id=101137284&redirect_uri=http%3A%2F%2Fuser.zhihuishu.com%2Fopen%2FQQCallbackDispatcher.do%3Fclient_name%3DQQClient&state=g12HDEwvHp') 
sleep(10)
click1 = driver.find_element_by_id('img_out_1447250889')
click1.double_click()

