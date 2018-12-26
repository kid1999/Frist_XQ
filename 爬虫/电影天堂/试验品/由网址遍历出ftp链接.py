 res = requests.get(url)                               #解析单个电影网址
            res.encoding = 'gb2312'
            soup = BeautifulSoup(res.text,'html.parser')

            title = soup.select('.co_content8 td  a')             #获取迅雷链接
            title = title[0].text
            if re.match(r'[*]',name):
                pass
            else:
                dict[name] = title                                #将名字对应迅雷链接放入dict