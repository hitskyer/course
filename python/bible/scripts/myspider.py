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
def getContent(txt):
	tmpdict = json.loads(txt)
	if "data" in tmpdict and "content" in tmpdict["data"]:
		txt = tmpdict["data"]["content"].encode("utf8")
		#pattern = "<span class=\"vn\">\d+</span>"
		#txt = re.sub(pattern, "", txt)
		#pattern = "<mark class=\"add\">"
		#txt = re.sub(pattern, "", txt)
		#pattern = "</mark>"
		#txt = re.sub(pattern, "", txt)
		return txt
	else:
		sys.stderr.write("getContent(.) failed.\n")
		sys.exit(-1)
def getSectionId(txt):
	pattern = "[a-zA-Z]*?.\d+.\d+"
	p       = re.search(pattern, txt)
	if p == None:
		sys.stderr.write("getSectionId(.) failed.\n")
		sys.exit(-1)
	else:
		return txt[p.start():p.end()]
def clean4topic(txt):
	txt = txt.replace("<h5>", "")
	txt = txt.replace("</h5>", "")
	return txt
def getSectionTxt(txt):
	pattern = "<.*?>"
	txt = re.sub(pattern, "", txt)
	return txt
def getEndForSection(txt, begin):
	end = txt.find("</div>", begin)
	if end > begin:
		return end + len("</div>")
	else:
		sys.stderr.write("getEndForSection(..) failed.\n")
		sys.exit(-1)
def getSectionInfo(txt, begin, p3, p4, sections):
	if p3 == None:
		sec_id  = getSectionId(txt[begin+p4.start():begin+p4.end()])
		sec_txt = getSectionTxt(txt[begin+p4.start():begin+p4.end()])
		sections.append([sec_id, sec_txt])
		begin  += p4.end()
	elif p4 == None:
		end     = getEndForSection(txt, begin+p3.start())
		sec_id  = getSectionId(txt[begin+p3.start():end])
		sec_txt = getSectionTxt(txt[begin+p3.start():end])
		sections.append([sec_id, sec_txt])
		begin   = end
	else:
		if p3.start() < p4.start():
			end     = getEndForSection(txt, begin+p3.start())
			sec_id  = getSectionId(txt[begin+p3.start():end])
			sec_txt = getSectionTxt(txt[begin+p3.start():end])
			sections.append([sec_id, sec_txt])
			begin   = end
		else:
			sec_id  = getSectionId(txt[begin+p4.start():begin+p4.end()])
			sec_txt = getSectionTxt(txt[begin+p4.start():begin+p4.end()])
			sections.append([sec_id, sec_txt])
			begin  += p4.end()
	return begin
def split4topic(txt, topics):
	pattern1  = "<h5>.*?</h5>"
	pattern2  = "<div class=\"p\">"
	#pattern3  = "<.*?\"[a-zA-Z]*?.\d+.\d+\".*?>.*?</.*?>"
	pattern3  = "<div id=\"[a-zA-Z]*?.\d+.\d+\" class=\"v\"><span class=\"vn\">\d+</span>"
	pattern4  = "<i class=\"pi\" for=\"[a-zA-Z]*?.\d+.\d+\">.*?</i>"
	begin     = 0
	pre_topic = ""
	paras     = []
	sections  = []
	while True:
		p1   = re.search(pattern1, txt[begin:])
		p2   = re.search(pattern2, txt[begin:])
		p3   = re.search(pattern3, txt[begin:])
		p4   = re.search(pattern4, txt[begin:])
		if p3 == None and p4 == None:
			if sections != []:
				paras.append(sections)
			if paras != []:
				topics.append([pre_topic, paras])
			break
		elif p2 == None:
			begin = getSectionInfo(txt, begin, p3, p4, sections)
		elif p1 == None:
			if (p3 != None and p3.start() < p2.start()) or (p4 != None and p4.start() < p2.start()):
				begin = getSectionInfo(txt, begin, p3, p4, sections)
			else:
				if sections != []:
					paras.append(sections)
					sections = []
				begin += p2.end()
		elif (p3 != None and p3.start() < p2.start() and p3.start() < p1.start()) or (p4 != None and p4.start() < p2.start() and p4.start() < p1.start()):
			begin = getSectionInfo(txt, begin, p3, p4, sections)
		elif p2.start() < p3.start() and p2.start() < p1.start():
			if sections != []:
				paras.append(sections)
				sections = []
			begin += p2.end()
		elif p1.start() < p3.start() and p1.start() < p2.start():
			if sections != []:
				paras.append(sections)
				sections = []
			if paras != []:
				topics.append([pre_topic, paras])
				paras = []
			pre_topic = clean4topic(txt[begin+p1.start():begin+p1.end()])
			begin += p1.end()
		else:
			sys.stderr.write("split4topic(..) failed.\n")
			sys.exit(-1)
def out4debug(topics):
	for infs in topics:
		topic = infs[0]
		print "---------%s---------" % (topic)
		for para in infs[1]:
			print "para"
			for section in para:
				print "\t%s:%s" % (section[0], section[1])
	print "\n\n"
def spider(spider_list, bible_file):
	for infs in spider_list:
		number = infs[1]
		pm     = ProxyMgr()
		for i in range(number):
			url = "http://wdbible.com/api/bible/chapterhtml/cunps/%s.%d" % (infs[0], i+1)
			txt = getContent(pm.getTextFromUrl(url))
			sys.stderr.write(txt + "\n")
			topics = []
			split4topic(txt, topics)
			out4debug(topics)
import sys
from ProxyMgr import *
import re
import json
try:
	bible_file = sys.argv[1]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" bible_file\n")
	sys.exit(-1)
spider_list = []
getSpiderList(spider_list)
spider(spider_list, bible_file)
