import urllib.request
respon = urllib.request.urlopen('http://placekitten.com/g/500/900')
cat_img = respon.read()
with open('cat_500_600.jpg','wb') as f:
	f.write(cat_img)
