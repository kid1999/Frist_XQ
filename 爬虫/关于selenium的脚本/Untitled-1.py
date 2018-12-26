from selenium import webdriver
import time 
driver = webdriver.Chrome()


driver.get('http://116.13.207.7/xxjsjy.aspx?zgh=13035&xm=%B3%C2%D1%E0%BB%AA&gnmkdm=N122309')   
driver.find_element_by_xpath('/html/body/h2/a').click()



