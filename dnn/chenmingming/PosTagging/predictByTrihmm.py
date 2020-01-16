# -*- coding:utf-8 -*-
# Python 3.7
# @Time: 2020/1/16 22:37
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: predictByTrihmm.py

import sys
import math
try:
	infile     = sys.argv[1]
	model_file = sys.argv[2]
	outfile    = sys.argv[3]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile model_file outfile\n")
	sys.exit(-1)
gPosList  = []
transDict = {}
emitDict  = {}
loadModel(model_file, gPosList, transDict, emitDict)
predict(infile, gPosList, transDict, emitDict, outfile)