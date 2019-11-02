#!/usr/bin/env python

import math

str_100 = str(math.factorial(100))

ans = 0

for c in str_100:
	ans += int(c)

print ans

