from selenium import webdriver
import time 
driver = webdriver.Chrome()
driver.get('http://10.11.12.6/npels/studentdefault.aspx')
time.sleep(2)

id = driver.find_element_by_id('tbName')
id.send_keys(1704405135)
pd = driver.find_element_by_id('tbPwd')
pd.send_keys(111111)
time.sleep(2)
login = driver.find_element_by_id('btnLogin')
login.click()
cookies = driver.get_cookies()
time.sleep(2)

driver.switch_to_frame('mainFrame')
step1 = driver.find_element_by_id('sp_2018-0004-0041_College_English_NEW_Century_SecEdition_Integration_2')
step1.click()
time.sleep(2)

#step2 = driver.find_element_by_class_name('tagButton')
step2 = driver.find_element_by_id('ctl00_ContentPlaceHolder1_aContinue')
step2.click()

while len(driver.find_element_by_class_name('leaveMsg')) !=0:
    driver.find_element_by_class_name('leaveMsg').click()
    time.sleep(120)
                                                                                                                                                                                  
