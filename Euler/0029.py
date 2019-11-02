#!/usr/bin/env python

import math

pow_list = []

for i in range(2, 101):
	for j in range(2, 101):
		pow_list.append(i ** j)

pow_list = sorted(pow_list)

ans = 0

for i in range(len(pow_list) - 1):
	if pow_list[i] != pow_list[i + 1]:
		ans += 1

print ans

print pow_list[0:100]
