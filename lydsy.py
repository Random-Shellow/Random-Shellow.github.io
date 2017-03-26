#!/usr/bin/python3
# -*- coding: UTF-8 -*-
#Random Shellow
import urllib.request
import sys
ID=[['Zhangsan','ZS'],
    ['LiSi','LS']]
print("How Many Problems You Solved?(lydsy)\nRandom Shellow\nVersion 1.0\n\n")
for task in ID:
	print('ID:%-16s  Name:%-6s  AC: Asking...'%(task[0],task[1]),end='')
	sys.stdout.flush()
	urlrequest=urllib.request.urlopen('http://www.lydsy.com/JudgeOnline/userinfo.php?user=%s'%task[0])
	urlinfo=(urlrequest.read()).decode()
	a=urlinfo.find("<a href='status.php?user_id=%s&jresult=4'>"%task[0])
	a=a+len("<a href='status.php?user_id=%s&jresult=4'>"%task[0])
	b=urlinfo.find('</a>',a)
	urlinfo=urlinfo[a:b]
	print('\b\b\b\b\b\b\b\b\b         \b\b\b\b\b\b\b\b\b%s'%urlinfo,end='\n\n')
input('Press "Enter" to exit...')
