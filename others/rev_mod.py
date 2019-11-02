#!/usr/bin/env python

from collections import deque
import itertools as ite
import sys
import math

sys.setrecursionlimit(1000000)

INF = 10 ** 18
MOD = 10 ** 9 + 7

def rev_mod(num):
	pow_num = MOD - 2
	ret = 1
	while pow_num > 0:
		if pow_num % 2:
			ret *= num
			ret %= MOD
		num *= num
		num %= MOD
		pow_num /= 2
	return ret
