#!/usr/bin/env python

import math

pre = 0
cur = 1

index = 1

while True:
	hoge = cur
	cur = cur + pre
	pre = hoge
	index += 1
	
	if len(str(cur)) >= 1000:
		break
	

print cur
print index

