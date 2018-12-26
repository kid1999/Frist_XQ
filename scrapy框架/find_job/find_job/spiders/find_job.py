import scrapy
from find_job.items import FindJobItem

class Job_Spider(scrapy.Spider):
    name = 'find_job'

    def start_requests(self):
        urls = 'https://search.51job.com/list/000000,000000,0000,00,9,99,%2B,2,{}.html?lang=c&stype=1&postchannel=0000&workyear=99&cotype=99&degreefrom=99&jobterm=99&companysize=99&lonlat=0%2C0&radius=-1&ord_field=0&confirmdate=9&fromType=&dibiaoid=0&address=&line=&specialarea=00&from=&welfare='
        for n in range(2000)[1:]:         #总共2000页招聘信息
            url = urls.format(n)
            yield scrapy.Request(url=url, callback=self.parse)




    def parse(self,response):
        item = FindJobItem()
        # item['job_name'] = response.xpath('//*[@id="resultList"]/div/p/span/a/@title').extract()
        # item['company'] = response.xpath('//*[@id="resultList"]/div/span[1]/a/@title').extract()[1:]
        # item['address'] = response.xpath('//*[@id="resultList"]/div/span[2]/text()').extract()[1:]
        # item['money'] =  response.xpath('//*[@id="resultList"]/div/span[3]/text()').extract()[1:]
        # item['time'] =  response.xpath('//*[@id="resultList"]/div/span[4]/text()').extract()[1:]


        job_name = response.xpath('//*[@id="resultList"]/div/p/span/a/@title').extract()
        company = response.xpath('//*[@id="resultList"]/div/span[1]/a/@title').extract()
        address = response.xpath('//*[@id="resultList"]/div/span[2]/text()').extract()[1:]
        money =  response.xpath('//*[@id="resultList"]/div/span[3]/text()').extract()[1:]
        time =  response.xpath('//*[@id="resultList"]/div/span[4]/text()').extract()[1:]
        for a,b,c,d,e in zip(job_name,company,address,money,time):
            item['job_name'] = a
            item['company'] = b
            item['address'] = c
            item['money'] =  d
            item['time'] =  e

            yield item