# !/usr/local/bin/python
# -*- coding:utf8 -*-

def getSpiderList(spider_list):
	spider_list.append(["gen", 50, "创世纪", "旧约"])
	spider_list.append(["exo", 40, "出埃及记", "旧约"])
	spider_list.append(["lev", 27, "利未记", "旧约"])
	spider_list.append(["num", 36, "民数记", "旧约"])
	spider_list.append(["deu", 34, "申命记", "旧约"])
	spider_list.append(["jos", 24, "约书亚记", "旧约"])
	spider_list.append(["jdg", 21, "士师记", "旧约"])
	spider_list.append(["rut", 4, "路得记", "旧约"])
	spider_list.append(["1sa", 31, "撒母耳记上", "旧约"])
	spider_list.append(["2sa", 24, "撒母耳记下", "旧约"])
	spider_list.append(["1ki", 22, "列王纪上", "旧约"])
	spider_list.append(["2ki", 25, "列王纪下", "旧约"])
	spider_list.append(["1ch", 29, "历代志上", "旧约"])
	spider_list.append(["2ch", 36, "历代志下", "旧约"])
	spider_list.append(["ezr", 10, "以斯拉记", "旧约"])
	spider_list.append(["neh", 13, "尼希米记", "旧约"])
	spider_list.append(["est", 10, "以斯帖记", "旧约"])
	spider_list.append(["job", 42, "约伯记", "旧约"])
	spider_list.append(["psa", 150, "诗篇", "旧约"])
	spider_list.append(["pro", 31, "箴言", "旧约"])
	spider_list.append(["ecc", 12, "传道书", "旧约"])
	spider_list.append(["sng", 8, "雅歌", "旧约"])
	spider_list.append(["isa", 66, "以赛亚书", "旧约"])
	spider_list.append(["jer", 52, "耶利米书", "旧约"])
	spider_list.append(["lam", 5, "耶利米哀歌", "旧约"])
	spider_list.append(["ezk", 48, "以西结书", "旧约"])
	spider_list.append(["dan", 12, "但以理书", "旧约"])
	spider_list.append(["hos", 14, "何西阿书", "旧约"])
	spider_list.append(["jol", 3, "约珥书", "旧约"])
	spider_list.append(["amo", 9, "阿摩司书", "旧约"])
	spider_list.append(["oba", 1, "俄巴底亚书", "旧约"])
	spider_list.append(["jon", 4, "约拿书", "旧约"])
	spider_list.append(["mic", 7, "弥迦书", "旧约"])
	spider_list.append(["nam", 3, "那鸿书", "旧约"])
	spider_list.append(["hab", 3, "哈巴谷书", "旧约"])
	spider_list.append(["zep", 3, "西番雅书", "旧约"])
	spider_list.append(["hag", 2, "哈该书", "旧约"])
	spider_list.append(["zec", 14, "撒迦利亚书", "旧约"])
	spider_list.append(["mal", 4, "玛拉基书", "旧约"])
	
	spider_list.append(["mat", 28, "马太福音", "新约"])
	spider_list.append(["mrk", 16, "马可福音", "新约"])
	spider_list.append(["luk", 24, "路加福音", "新约"])
	spider_list.append(["jhn", 21, "约翰福音", "新约"])
	spider_list.append(["act", 28, "使徒行传", "新约"])
	spider_list.append(["rom", 16, "罗马书", "新约"])
	spider_list.append(["1co", 16, "哥林多前书", "新约"])
	spider_list.append(["2co", 13, "哥林多后书", "新约"])
	spider_list.append(["gal", 6, "加拉太书", "新约"])
	spider_list.append(["eph", 6, "以弗所书", "新约"])
	spider_list.append(["php", 4, "腓立比书", "新约"])
	spider_list.append(["col", 4, "歌罗西书", "新约"])
	spider_list.append(["1th", 5, "帖撒罗尼迦前书", "新约"])
	spider_list.append(["2th", 3, "帖撒罗尼迦后书", "新约"])
	spider_list.append(["1ti", 6, "提摩太前书", "新约"])
	spider_list.append(["2ti", 4, "提摩太后书", "新约"])
	spider_list.append(["tit", 3, "提多书", "新约"])
	spider_list.append(["phm", 1, "腓利门书", "新约"])
	spider_list.append(["heb", 13, "希伯来书", "新约"])
	spider_list.append(["jas", 5, "雅各书", "新约"])
	spider_list.append(["1pe", 5, "彼得前书", "新约"])
	spider_list.append(["2pe", 3, "彼得后书", "新约"])
	spider_list.append(["1jn", 5, "约翰一书", "新约"])
	spider_list.append(["2jn", 1, "约翰二书", "新约"])
	spider_list.append(["3jn", 1, "约翰三书", "新约"])
	spider_list.append(["jud", 1, "犹大书", "新约"])
	spider_list.append(["rev", 22, "启示录", "新约"])
	total = 0
	for infs in spider_list:
		total += infs[1]
	print "total = %d" % (total)
def spider(spider_list, bible_file):
	for infs in spider_list:
		number = infs[1]
		pm     = ProxyMgr()
		for i in range(number):
			url = "http://wdbible.com/api/bible/chapterhtml/cunps/%s.%d" % (infs[0], i+1)
			txt = pm.getTextFromUrl(url)
			print url
			print txt
			print "\n\n"
import sys
from ProxyMgr import *
try:
	bible_file = sys.argv[1]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" bible_file\n")
	sys.exit(-1)
spider_list = []
getSpiderList(spider_list)
spider(spider_list, bible_file)
