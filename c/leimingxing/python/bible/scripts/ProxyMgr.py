# !/usr/local/bin/python
# -*- coding:utf8 -*-

import sys
import json
import time
import urllib2
class ProxyMgr:
	def __init__(self):
		self.internal_proxy_address = "http://10.10.10.149:8099/catcher/proxy?type=douban&rn=1"
		self.start_time_4_proxy     = time.time()
		self.headers                = ("User-Agent","Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.221 Safari/537.36 SE 2.X MetaSr 1.0")
		self.opener                 = self.getOpener()
	def getOpener(self):
		while True:
			try:
				json_str = urllib2.urlopen(self.internal_proxy_address, timeout=3).read()
				tmpdict  = json.loads(json_str)
				proxies  = {"https":tmpdict["data"][0]}
				proxy_s  = urllib2.ProxyHandler(proxies)
				opener   = urllib2.build_opener(proxy_s)
				opener.addheaders = [self.headers]
				sys.stderr.write("set proxy to %s success.\n" % (tmpdict["data"][0]))
				return opener
			except:
				sys.stderr.write("getOpener(.) failed.\n")
				time.sleep(2)
				continue
	def success(self, url, txt):
		if url.find("douban") >= 0:
			if txt.find("豆瓣评分") >= 0:
				return True
			elif txt.find("简介") >= 0:
				return True
			elif txt.find("你想访问的页面不存在") >= 0:
				return True
			else:
				return False
		elif url.find("baike") >= 0:
			if txt.find("编辑次数") >= 0:
				return True
			elif txt.find("\"pv\"") >= 0:
				return True
			elif txt.find("您所访问的页面不存在") >= 0:
				return True
			else:
				return False
		else:
			return True
	def toUtf8(self, url, txt):
		try:
			return txt.decode("utf8").encode("utf8")
		except:
			try:
				return txt.decode("gb18030").encode("utf8")
			except:
				sys.stderr.write("ProxyHandler::toUtf8(...) failed : %s\n" % (url))
				return ""
	def getTextFromUrl(self, url):
		indx = 0
		while True:
			indx += 1
			if indx > 3:
				sys.stderr.write("getTextFromUrl(..) failed for url=%s\n" % (url))
				return ""
			try:
				if time.time()-10 > self.start_time_4_proxy:
					self.start_time_4_proxy = time.time()
					self.opener             = self.getOpener()
				txt = self.opener.open(url, timeout=3).read()
				txt = self.toUtf8(url, txt)
				if self.success(url, txt) == True:
					sys.stderr.write("getTextFromUrl(..) success for url=%s\n" % (url))
					return txt
				else:
					self.start_time_4_proxy = time.time()
					self.opener             = self.getOpener()
			except Exception, e:
				sys.stderr.write("get except in getTextFromUrl(..) url = %s, Exception : %s\n" % (url, str(e)))
				self.start_time_4_proxy = time.time()
				self.opener             = self.getOpener()
if __name__ == "__main__":
	def isUtf8(txt):
		try:
			txt = txt.decode("utf8").encode("utf8")
			return True
		except:
			return False
	url_lst = [
		"https://movie.douban.com",
		"https://movie.douban.com/subject/25837262",
		"http://product.dangdang.com/23464478.html",
		"https://www.amazon.cn/dp/B01JIF6NJO",
		"https://item.jd.com/11452840.html",
		"https://sclub.jd.com/comment/productCommentSummaries.action?referenceIds=11571769438"]
	pm      = ProxyMgr()
	for url in url_lst:
		if isUtf8(pm.getTextFromUrl(url)) == True:
			print "success, the charset of url = %s is utf8." % (url)
		else:
			print "failed, the charset of url = %s is not utf8." % (url)
