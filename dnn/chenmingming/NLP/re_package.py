# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/12/2 19:30
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: re_package.py
# @Reference: 

import re
def text_match(text, pattern):
    if re.search(pattern, text):
        return "找到一个匹配！"
    else:
        return "没有找到匹配！"

# print(text_match('ac', 'ab?'))
# print(text_match('bc', 'ab?'))
# print(text_match('abc', 'ab?'))
# print(text_match('abbc', 'ab?'))


# print(text_match('ac', 'ab*'))
# print(text_match('bc', 'ab*'))
# print(text_match('abc', 'ab*'))
# print(text_match('abbc', 'ab*'))

# print(text_match('ac', 'ab+'))
# print(text_match('bc', 'ab+'))
# print(text_match('abc', 'ab+'))
# print(text_match('abbc', 'ab+'))


# print(text_match('abc', 'ab{2}'))
# print(text_match('abbc', 'ab{2}'))
# print(text_match('abbbbc', 'ab{3,5}?'))

# print(text_match('abbbc', '^\w+'))
# print(text_match('1abbbc', '^\w+'))
# print(text_match('_abbbc', '^\w+'))
# print(text_match('@abbbc', '^\w+'))

# print(text_match('abbbc def', '\s'))
# print(text_match('abbbcdef', '\s'))

print(text_match('abbbc def', '\Bd\B'))
print(text_match('abbbcdef', '\Bg'))

text = "love never fails.\nlove is forgive"
for mat in re.finditer('love', text):
    s = mat.start()
    e = mat.end()
    print('find %s at %d:%d'%(text[s:e], s, e))