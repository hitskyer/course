# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/8/22 10:03
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: ex1.1.py
# @Reference: 

import collections

Card = collections.namedtuple('Card_name', ['rank', 'suit'])
print(Card.__doc__)  # Card_name(rank, suit)


class FrenchDeck:
    ranks = [str(n) for n in range(2, 11)] + list('JKQA')
    suits = 'spades diamonds clubs hearts'.split()

    def __init__(self):
        self._cards = [Card(rank, suit) for suit in self.suits for rank in self.ranks]

    def __len__(self):
        return len(self._cards)

    def __getitem__(self, pos):
        return self._cards[pos]


deck = FrenchDeck()
print(len(deck))  # 13*4=52
print(deck[0])  # [] 调用 __getitem__ 方法
# Card_name(rank='2', suit='spades')

from random import choice

print(choice(deck))  # Card_name(rank='4', suit='clubs') 随机
print(choice(deck))  # Card_name(rank='J', suit='diamonds')
print(choice(deck))  # Card_name(rank='3', suit='clubs')

# __getitem__ 支持切片操作
# 取出前3个
print(deck[:3])
# 取出 A的所有项
print(deck[12::13])  # 12 开始 结束没有写默认结尾，每隔13个取一次

# __getitem__ 反向迭代也可以
for card in reversed(deck):
    print(card)

# 没有实现 __contains__ 方法，in 顺序做一次迭代搜索
print(Card('Q', 'hearts') in deck)  # True
print(Card('7', 'abc') in deck)  # False

# 排序
suit_values = dict(spades=3, hearts=2, diamonds=1, clubs=0)


def spades_high(card):
    # 自定义牌的 rank_value
    rank_value = FrenchDeck.ranks.index(card.rank)
    return rank_value * len(suit_values) + suit_values[card.suit]


# 自定义排序
for card in sorted(deck, key=spades_high):
    print(card)

from math import hypot  # 返回模长 Euclidean distance


class Vector:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):  # 打印的时候输出内容
        print("调用__repr__")
        # %r 获取 各个属性的标准字符串表示形式
        return 'Vector(%r, %r)' % (self.x, self.y)
        # __str__() 是在 str() 或 print() 时调用，返回的字符串更友好
        # 请优先使用 __repr__, 如果调用 str() 但是有没有实现，
        # 解释器自动用 __repr__ 代替

    # def __str__(self):
    #     return "print() 优先调用 __str__()"

    def __abs__(self):
        print("调用__abs__")
        return hypot(self.x, self.y)

    def __bool__(self):
        print("调用__bool__")
        # bool(x) 调用 x.__bool__(), 如果不存在，则调用 x.__len__()
        return bool(abs(self))
        # 或者
        # return (self.x or self.y) # 更高效

    def __add__(self, other):
        print("调用__add__")
        x = self.x + other.x
        y = self.y + other.y
        # 原则：不改变输入，创建新的输出
        return Vector(x, y)

    def __mul__(self, scalar):
        print("调用__mul__")
        # 原则：不改变输入，创建新的输出
        return Vector(self.x * scalar, self.y * scalar)

    def __rmul__(self, scalar):  # 交换律
        print("调用__rmul__")
        # 原则：不改变输入，创建新的输出
        return Vector(self.x * scalar, self.y * scalar)


v1 = Vector(2, 4)
v2 = Vector(2, 1)
v3 = v1 + v2  # 调用__add__
print(v3)  # 调用__repr__  Vector(4, 5)
print(abs(v3))  # 调用__abs__  6.4031242374328485
print(bool(v3))  # 调用__bool__  调用__abs__  True
print(v3 * 3)  # 调用__mul__  调用__repr__  Vector(12, 15)
print(3 * v3)  # 调用__rmul__ 调用__repr__  Vector(12, 15)
print(str(v3))  # 调用__repr__  Vector(4, 5)
