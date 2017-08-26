#week03solution03-2.py
#random list

#引入随机工具模块random
import random

#python生成器(generator)的高级语法：生成100个随机数，直接放在一个列表里，并赋值给x
x=[random.randint(1,9) for i in range(100)]

#打印列表x
print(x)
