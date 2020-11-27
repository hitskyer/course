# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/11/27 19:32
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: word_cloud.py
# @Reference: 

import jieba
import numpy as np
from PIL import Image
from wordcloud import WordCloud

stopwords = []
with open("stopwords.txt", 'r', encoding='utf-8') as f:
    for w in f:
        stopwords.append(w.replace('\n', ''))

with open('processed_txt.txt', 'w', encoding='utf-8') as processed:
    words_list = []
    with open("../shendiaoxialv.txt", 'r', encoding='utf-8') as f:
        for line in f:
            word = jieba.cut(line.replace('\t', '').replace('\n', '').replace(' ', ''))
            for w in word:
                if w not in stopwords and len(w) > 1:
                    words_list.append(w)
    processed.write(' '.join(words_list))

wordtxt = ""
with open('processed_txt.txt', 'r', encoding='utf-8') as f:
    wordtxt = f.read()

background_pic = np.array(Image.open('background.png'))
wc = WordCloud(
    background_color='white',
    max_words=300,
    # font_path='wb.ttf',
    min_font_size=10,
    max_font_size=100,
    width=1600,
    height=1200,
    mask=background_pic # 背景形状
)

wc.generate(wordtxt)
wc.to_file("wc.jpg")