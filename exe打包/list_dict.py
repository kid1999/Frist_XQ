

from collections import defaultdict
dict = {}
dict =defaultdict(list)

for n in ['a','b','c']:
    for i in range(5):
        dict[n].append(i)

print(dict['a'])
