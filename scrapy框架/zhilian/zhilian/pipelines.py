# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
import MySQLdb

class ZhilianPipeline(object):
    def open_spider(self,spider):
        db = spider.settings.get('MYSQL_DBNAME','zhilian')
        host = spider.settings.get('MYSQL_HOST', 'localhost')
        port = spider.settings.get('MYSQL_PORT', 3306)
        user = spider.settings.get('MYSQL_USER', 'root')
        passwd = spider.settings.get('MYSQL_PASSWORD', '123456')
        self.db_conn =MySQLdb.connect(host=host, port=port, db=db, user=user, passwd=passwd,charset="utf8",use_unicode=True)
        print('链接数据库成功')
        self.db_cur = self.db_conn.cursor()


    def close_spider(self, spider):
        #接收结束信号
        self.db_conn.close()
        print ('完成数据插入...............................')


    def process_item(self, item, spider):
        try:
        # 插入数据


            self.db_cur.execute(
                """insert into job_list(title, time, address, numbers ,industry,job_type,company,company_type,scale,
                introduction) values (%s, %s, %s, %s, %s,%s,%s,%s,%s,%s)""",(item['title'],item['time'],item['address'],item['numbers'],item['industry'],item['job_type'],item['company'],item['company_type'],item['scale'],item['introduction']))

            # 提交sql语句
            self.db_conn.commit()
            print('正在插入数据......................................')

        except Exception as error:
            # 出现错误时打印错误日志
            print(error)
        return item


