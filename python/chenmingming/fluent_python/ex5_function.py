def factorial(n):
    '''
    returns n! n的阶乘
    '''
    return 1 if n < 2 else n * factorial(n - 1)


print(factorial(42))
print(factorial.__doc__)  # returns n! n的阶乘
print(type(factorial))  # <class 'function'>

fact = factorial
print(fact)  # <function factorial at 0x0000021512868EA0>
print(fact(4))  # 24
print(list(map(factorial, range(11))))
# [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800]

fruits = ['strawberry', 'fig', 'apple', 'cherry', 'raspberry', 'banana']
print(sorted(fruits, key=len))  # 按长度排序


# ['fig', 'apple', 'cherry', 'banana', 'raspberry', 'strawberry']

def reveres(word):
    return word[::-1]


print(reveres("michael"))  # leahcim
print(sorted(fruits, key=reveres))
# ['banana', 'apple', 'fig', 'raspberry', 'strawberry', 'cherry']

print(sorted(fruits, key=lambda w: w[::-1]))
# ['banana', 'apple', 'fig', 'raspberry', 'strawberry', 'cherry']

print([callable(obj) for obj in (abs, str, 13, factorial)])  # [True, True, False, True]

import random


class BingoCage:
    def __init__(self, items):
        self._items = list(items)
        random.shuffle(self._items)

    def pick(self):
        try:
            return self._items.pop()
        except IndexError:
            raise LookupError("pick from empty BingoCage")

    def __call__(self):
        return self.pick()


arr = [1, 2, 3, 4, 5]
bc = BingoCage(arr);
print(bc._items)  # [1, 4, 3, 5, 2]
print(bc.pick())  # 2
print(bc._items)  # [1, 4, 3, 5]
print(bc())  # 5, bc 实现了 __call_() 可调用
print(bc._items)  # [1, 4, 3]
print(callable(bc))  # True


def tag(name, *content, cls=None, **attrs):
    """生成一个或多个HTML标签"""
    if cls is not None:
        attrs['class'] = cls
    if attrs:
        attr_str = ''.join(' %s="%s"' % (attr, value)
                           for attr, value
                           in sorted(attrs.items()))
    else:
        attr_str = ''
    if content:
        return '\n'.join('<%s%s>%s</%s>' %
                         (name, attr_str, c, name) for c in content)
    else:
        return '<%s%s />' % (name, attr_str)


print(tag('br'))  # <br />
print(tag('p', 'hello'))  # <p>hello</p>
print(tag('p', 'hello', 'world'))  # 第一个参数后的任意个 参数 被 *content 捕获，存入元组
# <p>hello</p>
# <p>world</p>
print(tag('p', 'hello', id=33, pid=24))  # 没有明确指定名称的关键字参数被 **attrs 捕获，存入字典
# <p id="33" pid="24">hello</p>
print(tag('p', 'hello', 'world', id=33, cls='sidebar', pid=24))  # cls 参数只能作为关键字参数
# <p class="sidebar" id="33" pid="24">hello</p>
# <p class="sidebar" id="33" pid="24">world</p>
print(tag(cont='testing', name="img"))
# <img cont="testing" />
my_tag = {'name': 'img', 'title': 'Sunset Boulevard',
          'src': 'sunset.jpg', 'cls': 'framed'}
print(tag(**my_tag))  # ** 字典中所有元素作为单个参数传入，同名键绑定到对应具名参数，余下被 **attrs 捕获


# <img class="framed" src="sunset.jpg" title="Sunset Boulevard" />

def f(a, *c, b):
    return a, b


print(f(1, b=2))  # (1, 2)
print(f(1, 2, b=3))  # (1, 3) b= 必须写，因为前面有 * 参数


# print(f(1, 2))  # f() takes 1 positional argument but 2 were given

def f1(a, b, *c):
    return a, b


print(f1(1, b=2))  # (1, 2)
print(f1(1, 2))  # (1, 2)
print(f1(1, 2, 3))  # (1, 2)

from inspect import signature

sig = signature(tag)
print(sig)  # (name, *content, cls=None, **attrs)
my_tag = {'name': 'img', 'title': 'Sunset Boulevard',
          'src': 'sunset.jpg', 'cls': 'framed'}
bound_args = sig.bind(**my_tag)
print(bound_args)
# <BoundArguments (name='img', cls='framed', attrs={'title': 'Sunset Boulevard', 'src': 'sunset.jpg'})>
del my_tag['name']


# bound_args = sig.bind(**my_tag)
# TypeError: missing a required argument: 'name'

def clip(text: str, max_len: 'int > 0' = 80) -> str:
    pass


print(clip.__annotations__)  # 一个字典
# 注解可以是 类 或者 字符串
# {'text': <class 'str'>, 'max_len': 'int > 0', 'return': <class 'str'>}
sig = signature(clip)
print(sig)  # (text: str, max_len: 'int > 0' = 80) -> str
print(sig.return_annotation)  # <class 'str'>
for param in sig.parameters.values():
    print(param.name, " ", param.annotation, " ", param.default)
# text   <class 'str'>   <class 'inspect._empty'>
# max_len   int > 0   80


from functools import reduce


def fact(n):
    return reduce(lambda a, b: a * b, range(1, n + 1))


print(fact(5))

from operator import mul


def fact1(n):
    return reduce(mul, range(1, n + 1))


print(fact1(5))

metro_data = [
    ('Tokyo', 'JP', 36.933, (35.689722, 139.691667)),
    ('Delhi NCR', 'IN', 21.935, (28.613889, 77.208889)),
    ('Mexico City', 'MX', 20.142, (19.433333, -99.133333)),
    ('New York-Newark', 'US', 20.104, (40.808611, -74.020386)),
    ('Sao Paulo', 'BR', 19.649, (-23.547778, -46.635833)),
]
from operator import itemgetter
import operator

for city in sorted(metro_data, key=itemgetter(1)):
    print(city)  # 按照 索引 1 排序

cc_name = itemgetter(1, 0)
for city in metro_data:
    print(cc_name(city))
# ('JP', 'Tokyo')
# ('IN', 'Delhi NCR')
# ('MX', 'Mexico City')
# ('US', 'New York-Newark')
# ('BR', 'Sao Paulo')

print([name for name in dir(operator) if not name.startswith('_')])
# ['abs', 'add', 'and_', 'attrgetter', 'concat', 'contains', 'countOf',
# 'delitem', 'eq', 'floordiv', 'ge', 'getitem', 'gt', 'iadd', 'iand',
# 'iconcat', 'ifloordiv', 'ilshift', 'imatmul', 'imod', 'imul', 'index',
# 'indexOf', 'inv', 'invert', 'ior', 'ipow', 'irshift', 'is_', 'is_not',
# 'isub', 'itemgetter', 'itruediv', 'ixor', 'le', 'length_hint', 'lshift',
# 'lt', 'matmul', 'methodcaller', 'mod', 'mul', 'ne', 'neg', 'not_', 'or_',
# 'pos', 'pow', 'rshift', 'setitem', 'sub', 'truediv', 'truth', 'xor']

from operator import methodcaller

s = 'the time has come'
upcase = methodcaller('upper')
print(upcase(s))  # THE TIME HAS COME
connect = methodcaller('replace', ' ', '-')
print(connect(s))  # the-time-has-come

from operator import mul
from functools import partial

triple = partial(mul, 3)
print(triple(7))  # 21
print(list(map(triple, range(1, 10))))
# [3, 6, 9, 12, 15, 18, 21, 24, 27]
