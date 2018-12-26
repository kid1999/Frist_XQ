from appium import webdriver

desired_caps = {}
desired_caps['platformName'] = 'Android'
desired_caps['platformVersion'] = '7.0'
desired_caps['deviceName'] = 'VS987857052fe'         #手机id
desired_caps['appPackage'] = 'com.lptiyu.tanke'    #包名
desired_caps['appActivity'] = '.activities.main.MainActivity'         #启动页名

driver = webdriver.Remote('http://localhost:4723/wd/hub', desired_caps)

#元素定位:
driver.find_element_by_id("com.lptiyu.tanke:id/tv_enterRun").click()
driver.quit()