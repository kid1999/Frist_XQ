from appium import webdriver

desired_caps = {}
desired_caps['platformName'] = 'Android'
desired_caps['platformVersion'] = '7.0'
desired_caps['deviceName'] = 'VS987857052fe'         #手机id
desired_caps['appPackage'] = 'com.android.calculator2'    #包名
desired_caps['appActivity'] = '.Calculator'         #启动页名

driver = webdriver.Remote('http://localhost:4723/wd/hub', desired_caps)

#元素定位:
driver.find_element_by_id("com.android.calculator2:id/digit1").click()
driver.find_element_by_id("com.android.calculator2:id/plus").click()
driver.find_element_by_id("com.android.calculator2:id/digit1").click()
driver.find_element_by_id("com.android.calculator2:id/equal").click()

# driver.quit()