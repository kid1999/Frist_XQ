from selenium import webdriver
driver = webdriver.Chrome()
driver.get('https://www.baidu.com/?tn=93153557_hao_pg') 
input1 = driver.find_element_by_id('kw')
input1.send_keys('python')
input1.submit()