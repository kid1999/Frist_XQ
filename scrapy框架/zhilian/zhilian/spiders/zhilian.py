import scrapy
import re
from zhilian.items import ZhilianItem
import time

class zhilian_Spider(scrapy.Spider):
    name = 'zhilian'
    def start_requests(self):
        urls = 'https://xiaoyuan.zhaopin.com/full/0/0_0_0_0_0_-1_0_{}_0'  #全职
        #urls = 'https://xiaoyuan.zhaopin.com/part/0/0_0_0_0_0_-1_0_{}_0'  #实习
        for n in range(6784)[160:]:         #总共9392页招聘信息
            url = urls.format(n)
            time.sleep(1)
            yield scrapy.Request(url=url, callback=self.parse)


    def parse(self,response):
        item = ZhilianItem()

        title = response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[1]/div[2]/p[1]/a/text()').extract()  #名称
        address = response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[1]/div[2]/p[2]/span[1]/span/em/text()').extract()  #地址
        numbers =  response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[1]/div[2]/p[2]/span[2]/span/em/text()').extract()  #人数
        industry =  response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[2]/p[4]/span[3]/span/em/text()').extract()  #行业
        introduction = response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[2]/p[6]').extract()  #未处理的简介   s = re.findall(r'1.+',soup.text)
        company_type = response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[2]/p[4]/span[1]/span/em/text()').extract() #公司类型
        scale = response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[2]/p[4]/span[2]/span/em/text()').extract() #公司规模
        job_type = response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[2]/p[4]/span[4]/span/em/text()').extract() #职位类别
        company =  response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[2]/p[2]/span/text()').extract() #公司名
        time = response.xpath('/html/body/div[2]/div[3]/div[1]/div/div[2]/ul/li/div[1]/div[2]/p[3]/span/span/text()[2]').extract() #发布时间

        for a,b,c,d,e,f,g,h,i,j in zip(title,address,numbers,industry,introduction,company_type,company,scale,job_type,time):
            item['title'] = a
            item['time'] = j
            item['address'] = b
            item['numbers'] = c
            item['industry'] = d
            item['job_type'] = i
            item['company'] = g
            item['company_type'] = f
            item['scale'] = h
            item['introduction'] = re.findall(r'<span>.+?</span>',e)
            yield item





















