import urllib.request
resp=urllib.request.urlopen('http://www.baidu.com')
html=resp.read()
print(html)


