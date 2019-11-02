#!/usr/bin/env python

import math

s = "0"

for i in range(1000000):
	s += str(i + 1)

print int(s[1]) * int(s[10]) * int(s[100]) * int(s[1000]) * int(s[10000]) * int(s[100000]) * int(s[1000000])

