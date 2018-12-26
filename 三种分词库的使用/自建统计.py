
#统计单词出现次数
# str = "hello xiaoming i am jack "
# letter_counts = {letter: str.count(letter) for letter in set(str) if letter.lower()}
# print(letter_counts)

# 统计空格隔开的单词出现次数
str = "hello xiaoming i am jack "
print({letter: str.count(letter) for letter in str.split(" ") })

#           从父串 统计 子串出现的次数 