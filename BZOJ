#!/usr/bin/python3
# -*- coding: UTF-8 -*-
#Random Shellow
import urllib.request
import sys
ID=[['',''],
    ['','']]
print("Who Solved the Problem?(lydsy)\nRandom Shellow\nVersion 1.0")
while True:
	userinput=input("\n> ")
	if(userinput=='q' or userinput=='Q'):
		exit()
	for task in ID:
		print("\nID:%-16s  Name:%-6s  AC:Asking..."%(task[0],task[1]),end='')
		sys.stdout.flush()
		urlrequest=urllib.request.urlopen('http://www.lydsy.com/JudgeOnline/userinfo.php?user=%s'%task[0])
		urlinfo=(urlrequest.read()).decode()
		a=urlinfo.find("p(%s);"%userinput)
		if(a==-1):
			print("\b\b\b\b\b\b\b\b\b         \b\b\b\b\b\b\b\b\bNo")
		else:
			print("\b\b\b\b\b\b\b\b\b         \b\b\b\b\b\b\b\b\bYes")
	print()
