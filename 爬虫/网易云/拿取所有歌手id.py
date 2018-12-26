import requests
from bs4 import BeautifulSoup

headers={'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',  
             'Accept-Encoding': 'gzip, deflate',  
             'Accept-Language': 'zh-CN,zh;q=0.9',  
             'Connection': 'keep-alive',  
             'Cookie': '__f_=1528453610885; _ntes_nnid=86ca768477bb7f2845ba15aa9e5d5f76,1528453621951; _ntes_nuid=86ca768477bb7f2845ba15aa9e5d5f76; hb_MA-BFF5-63705950A31C_source=www.baidu.com; hb_MA-BFF5-63705950A31C_u=%7B%22utm_source%22%3A%20%22baidu%22%2C%22utm_medium%22%3A%20%22cpc%22%2C%22utm_campaign%22%3A%20%22affiliate%22%2C%22utm_content%22%3A%20%22SEM%22%2C%22utm_term%22%3A%20%22Brand_1yuan%22%2C%22promotional_id%22%3A%20%22%22%7D; _iuqxldmzr_=32; __remember_me=true; usertrack=ezq0plsvrCSfCzfViOxTAg==; Province=0770; City=0777; _ga=GA1.2.259053257.1529850917; WM_TID=nTNMKeqxLHYMnOyCBxdMJ7biHUv40RjS; JSESSIONID-WYYY=ZNzBfkj9FZFANbqNdUgRtORGZ6aeYQekIB%2BD%5CXwZ7oy2xIU9HHms449aNDrTmO5Xc%2FZrzt69IrrnFws7le6I%5CV42AHXbohSoGaOpXKtT4CuHAT3Q%5C4FAinFawrJ5o%2BH6W2%2FPQkR9zbb57WUN2GYNnHcjb0C9HiONDyo%5Cc3QyrNQhYoEn%3A1530010539908; __utma=94650624.455812456.1529758934.1529923744.1530008740.12; __utmc=94650624; __utmz=94650624.1530008740.12.9.utmcsr=baidu|utmccn=(organic)|utmcmd=organic; MUSIC_U=9234844d991fd7b9411015751446d9fa185c1fecc984463a3f11fb1cc84047111c168043df6b8a0f49074fe9a24e91ee70b13fe1356db7fae9140ea79665eff9299ec3a827e93637bf122d59fa1ed6a2; __csrf=d337e5af5c65fde15513966166e1887c; __utmb=94650624.52.10.1530008740',  
             'Host': 'music.163.com',  
             'Referer': 'http://music.163.com/',  
             'Upgrade-Insecure-Requests': '1',  
             'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '  
                           'Chrome/66.0.3359.181 Safari/537.36'}  





ls1 = [1001, 1002, 1003, 2001, 2002, 2003, 6001, 6002, 6003, 7001, 7002, 7003, 4001, 4002, 4003]    # id的值  
ls2 = [-1, 0, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90] # initial的值  
for i in ls1:  
    for j in ls2:  
        url = 'http://music.163.com/discover/artist/cat?id=' + str(i) + '&initial=' + str(j)  
        res = requests.get(url,headers =headers)
        print(res.text)