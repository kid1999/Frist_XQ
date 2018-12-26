import re

# 匹配字符
str = 'Hello 123 4567 World_This is a Regex Demo'

# re.match函数
# re.match 尝试从字符串的起始位置匹配一个模式，如果不是起始位置匹配成功的话，match()就返回none。

#最常规的匹配
# result = re.match('^Hello\s\d\d\d\s\d{4}\s\w{10}.*Demo$',str)
# print(result)          #返回一个方法
# print(result.group())  #匹配的字符串
# print(result.span())   #匹配的字符串的位置

#泛匹配:
# result = re.match('^Hello.*Demo',str)
# print(result)

#匹配目标
# str = 'Hello 1234567 World_This is a Regex Demo'
# result = re.match('^Hello\s(\d+)\sWorld.*Demo$',str)
# print(result.group(1))    #拿到第一个括号里匹配的元素

#贪婪匹配:  .*会尽可能数据多的
# str = 'Hello 1234567 World_This is a Regex Demo'
# result = re.match('^He.*(\d+).*Demo$',str)
# print(result)
# print(result.group(1))   

#非贪婪模式  匹配尽可能少的数据
# str = 'Hello 1234567 World_This is a Regex Demo'
# result = re.match('^He.*?(\d+).*Demo$',str)
# print(result)
# print(result.group(1))   

# 匹配模式
# str = '''Hello 1234567 World_This
# is a Regex Demo
# '''
# # result = re.match('^He.*?(\d+).*?Demo$',str)
# # print(result)   #此时无法匹配, 因为 . 无法匹配换行符在这个模式下
# result = re.match('^He.*?(\d+).*?Demo$',str,re.S)
# print(result)
# print(result.group(1))  #在re.S模式下 . 可以匹配换行符

#转义
# str = 'price is $5.00'   #对于$这种符号 用转义
# result = re.match('price is \$5.00',str)
# print(result)

#总结  尽量使用范匹配 使用括号得到匹配目标 尽量使用非贪婪模式 有换行符就用re.S







