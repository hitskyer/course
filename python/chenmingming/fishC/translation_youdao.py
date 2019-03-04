import urllib.request
import urllib.parse
import json
import time

while True:
    content = input('请输入需要翻译的内容(输入q退出)：')
    if content == 'q':
        break
    
    url = 'http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule'
    # 添加浏览器访问标识，以免被服务器拒绝代码访问
    head = {}
    head['User-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.140 Safari/537.36 Edge/18.17763'
    data = {}
    data['action'] = 'FY_BY_CLICKBUTTION'
    data['bv'] = '908078567e4fa99e9a8b55bb7ca876a4'
    data['client'] = 'fanyideskweb'
    data['doctype'] = 'json'
    data['from'] = 'AUTO'
    data['i'] = content
    data['keyfrom'] = 'fanyi.web'
    data['salt'] = '15502931659548'
    data['sign'] = 'aa701829ba3c889ac50fb1666957321c'
    data['smartresult'] = 'dict'
    data['to'] = 'AUTO' 
    data['ts'] = '1550293165954'
    data['typoResult'] = 'false'
    data['version'] = '2.1'

    data = urllib.parse.urlencode(data).encode('utf-8')
    req = urllib.request.Request(url,data,head)
    response = urllib.request.urlopen(req)
    html = response.read().decode('utf-8')
    tar = json.loads(html)

    print('翻译的结果是：',tar['translateResult'][0][0]['tgt'])
    time.sleep(5)#休息5秒


