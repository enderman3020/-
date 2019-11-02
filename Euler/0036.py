#!/usr/bin/env python

import math

ans = 0

for i in range(1000000):
	piyo = str(i)
	if piyo != piyo[::-1]:
		continue
	piyo = str(bin(i))
	piyo = piyo[2:]
	if piyo != piyo[::-1]:
		continue
	print str(i) + " " + str(piyo)
	ans += i

print ans

