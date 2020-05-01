# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/5/1 10:27
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 17.LSA.py
# @Reference: https://cloud.tencent.com/developer/article/1530432
import numpy as np
from sklearn.decomposition import TruncatedSVD  # LSA 潜在语义分析
from sklearn.feature_extraction.text import TfidfVectorizer  # 将文本集合转成权值矩阵

# 5个文档
docs = ["Love is patient, love is kind. It does not envy, it does not boast, it is not proud.",
        "It does not dishonor others, it is not self-seeking, it is not easily angered, it keeps no record of wrongs.",
        "Love does not delight in evil but rejoices with the truth.",
        "It always protects, always trusts, always hopes, always perseveres.",
        "Love never fails. But where there are prophecies, they will cease; where there are tongues, \
        they will be stilled; where there is knowledge, it will pass away. (1 Corinthians 13:4-8 NIV)"]
vectorizer = TfidfVectorizer()
X = vectorizer.fit_transform(docs)  # 转成权重矩阵
print("--------转成权重矩阵---------")
print(X)
print("--------获取特征（单词）---------")
words = vectorizer.get_feature_names()
print(words)
print(len(words), "个特征（单词）")  # 52个单词

topics = 4
lsa = TruncatedSVD(n_components=topics)  # 潜在语义分析，设置4个话题
X1 = lsa.fit_transform(X)  # 训练并进行转化
print("--------lsa奇异值---------")
print(lsa.singular_values_)
print("--------5个文本，在4个话题向量空间下的表示---------")
print(X1)  # 5个文本，在4个话题向量空间下的表示

pick_docs = 2  # 每个话题挑出2个最具代表性的文档
topic_docid = [X1[:, t].argsort()[:-(pick_docs + 1):-1] for t in range(topics)]
# argsort,返回排序后的序号
print("--------每个话题挑出2个最具代表性的文档---------")
print(topic_docid)

print("--------lsa.components_---------")
print(lsa.components_)  # 4话题*52单词
pick_keywords = 3  # 每个话题挑出3个关键词
topic_keywdid = [lsa.components_[t].argsort()[:-(pick_keywords + 1):-1] for t in range(topics)]
print("--------每个话题挑出3个关键词---------")
print(topic_keywdid)

print("--------打印LSA分析结果---------")
for t in range(topics):
    print("话题 {}".format(t))
    print("\t 关键词：{}".format(", ".join(words[topic_keywdid[t][j]] for j in range(pick_keywords))))
    for i in range(pick_docs):
        print("\t\t 文档{}".format(i))
        print("\t\t", docs[topic_docid[t][i]])
