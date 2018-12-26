from selenium import webdriver
from time import sleep
driver = webdriver.Chrome()
driver.get('http://ac.qq.com/ComicView/index/id/17114/cid/350') 
sleep(2)
for src in  driver.find_elements_by_css_selector('li img'):
    print(src)