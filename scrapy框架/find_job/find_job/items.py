# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class FindJobItem(scrapy.Item):
    job_name = scrapy.Field()
    company = scrapy.Field()
    address = scrapy.Field()
    money =  scrapy.Field()
    time =  scrapy.Field()
