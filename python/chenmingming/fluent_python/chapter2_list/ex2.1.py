# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2021/3/9 15:54
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: ex2.1.py
# @Reference:

# 列表推导有自己的局部作用域
x = "ABC"
y = [ord(x) for x in x]
print(x)  # ABC
print(y)  # [65, 66, 67]

# 列推导更简单
symbols = '$¢£¥€¤'
beyond_ascii = [ord(s) for s in symbols if ord(s) > 127]
print(beyond_ascii)  # [162, 163, 165, 8364, 164]
beyond_ascii = list(filter(lambda c: c > 127, map(ord, symbols)))
print(beyond_ascii)  # [162, 163, 165, 8364, 164]

colors = ['black', 'white']
sizes = ['S', 'M', 'L']
t_shirts = [(color, size) for color in colors for size in sizes]
print(t_shirts)
# [('black', 'S'), ('black', 'M'), ('black', 'L'),
# ('white', 'S'), ('white', 'M'), ('white', 'L')]

t_shirts = [(color, size) for size in sizes for color in colors]
print(t_shirts)
# [('black', 'S'), ('white', 'S'),
# ('black', 'M'), ('white', 'M'),
# ('black', 'L'), ('white', 'L')]

# 生成器表达式 ()
symbols = '$¢£¥€¤'
print(tuple(ord(symbol) for symbol in symbols))
import array

print(array.array('I', (ord(symbol) for symbol in symbols)))
# ord(symbol) 外面需要括号，因为array需要2个构造参数
# typecode (must be b, B, u, h, H, i, I, l, L, q, Q, f or d)

for t_shirt in ('{}, {}'.format(c, s) for c in colors for s in sizes):
    print(t_shirt)