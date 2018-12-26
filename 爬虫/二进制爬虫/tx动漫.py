import requests
import json
url = 'http://ac.gtimg.com/media/js/ac.page.chapter.view_v2.3.6.js?v=20170622'

header = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36',
'v': '20170622'}

res = requests.get(url,headers = header) 

json_data = json.loads(res)
print(json_data)

