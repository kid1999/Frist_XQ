# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class ZhilianItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    title =  scrapy.Field()
    address = scrapy.Field()
    numbers = scrapy.Field()
    industry = scrapy.Field()
    introduction = scrapy.Field()
    company_type = scrapy.Field()
    scale = scrapy.Field()
    job_type = scrapy.Field()
    company = scrapy.Field()
    time = scrapy.Field()
