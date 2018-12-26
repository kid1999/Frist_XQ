import re

# 匹配字符
str = 'pip install Hello 123 4567 World_This is a Regex Demo'

#  search 寻找字符串中符合的部分

# 示范1:
result = re.search('Hello\s\d\d\d\s\d{4}\s\w{10}.*Demo$',str)
print(result)          #返回一个方法
print(result.group())  #匹配的字符串
print(result.span())   #匹配的字符串的位置

# 示范2:










