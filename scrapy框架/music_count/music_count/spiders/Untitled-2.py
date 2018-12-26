
import json
import scrapy
import re


class music_Spider(scrapy.Spider):
    name = 'get_music_comment2'


#拿到密匙,url开始爬虫

    def start_requests(self):

        url = 'https://music.163.com/weapi/v1/resource/comments/R_SO_4_410801653?csrf_token='
        yield scrapy.FormRequest(
                url = url,
                formdata = {'params': 'rhHY7UpMVpBskPTA6vhHR+bpbCIxEDMjA4Ts6GG3uumFqNOyfnQn0DLZZEfJtz975hCG8RwaKI+WlIpB6OJOeXH1JqiLTY9Jd1gPDSoOgzwxb/9+jA51wInCtBcOFPFs2FIGX+jkjjmUz45Kye63in204qmMsajuhmYPUKICseGX/N56+geWqLKbBiapqmZ10KgRHqC7Hubo7qGKgu8ssEYC8mho3fuX7MwdXoD6uTQ=',            
'encSecKey': 'c60071d15daa3c76919959b93e8e4b81cb418e4eeb21b1a4f7eb130cc30d47358b2d72ec4f7da4e3199333e04ca9e743460b15059fb1c1942ce63af2501a5875ba3a64cf7d576b64bc25c3d039cd00be9c43d559cdf377c1499f1e1720c856488c5305d1b88742f6e284a7a0c10e190d14569f4d12e9416faf23eff91a3a0ea1'},
                callback = self.parse_page
            )


#爬虫内容:

    def parse_page(self,response):
        json_dict = json.loads(response.text)
        total_comment = json_dict['total']
        page=(total_comment/20)+1

        print (' ***查询到评论共计%d条,%d页***......................'%(total_comment,page))

        json_comment = json_dict['comments']
        for json_comment in json_comment:
            user_id = json_comment['user']['userId']
            user_name = json_comment['user']['nickname']
            comment = json_comment['content']
            likedCount = json_comment['likedCount']
            likedCount = int(likedCount)
            print('用户id',user_id)
            print('用户名',user_name)
            print('评论',comment)
            print('点赞数',int(likedCount))
        







   
