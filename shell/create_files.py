# -*- coding:utf8 -*-

def mycreate(root_dir, files):
	for i in range(10000):
		if 0 == i%100:
			cmd = "mkdir %s/%d" % (root_dir, int(i/100))
			os.popen(cmd)
		tmpfile = "%s/%d/%d" % (root_dir, int(i/100), int(i%100))
		os.popen("touch %s" % (tmpfile))
		files.append(tmpfile)
def mywrite(files):
	lst = ["zhangshujuan", "wansiqi", "xuxingjun",
		"niuhongli", "liushuo", "dongyaxing",
		"yangwenbin", "liuyanfu", "chenghuixian",
		"chenmingming", "jiachen", "zhengshaopeng",
		"wangrui", "liwei", "yaojianjiao",
		"liuyunpeng", "zhaojing", "juwenhui"]
	tmpdict = {}
	while len(tmpdict) < len(lst):
		i = int(random.random()*len(files))
		if i in tmpdict:
			continue
		else:
			name = lst[len(tmpdict)]
			outfile = files[i]
			fdo = open(outfile, "w")
			fdo.write(name+"\n")
			fdo.close()
			tmpdict[i] = 1
			print outfile, name
import sys
import os
import random
try:
	root_dir = sys.argv[1]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" root_dir\n")
	sys.exit(-1)
files = []
mycreate(root_dir, files)
mywrite(files)
