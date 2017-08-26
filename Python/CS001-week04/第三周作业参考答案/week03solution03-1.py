#week03solution03-1.py
#random list

#引入随机工具模块random
import random

#初始化一个空的列表赋值给x
x=[]

#循环100次，每次加入一个随机数到列表x
for i in range(100):
    x.append(random.randrange(1,10))

#打印列表x
print(x)
