#!/usr/bin/env python

from collections import deque
import itertools as it
import sys
import math

sys.setrecursionlimit(10000000)

MOD = 216063822110665427813261110433 # prime (30 digit)

A = ['a', 'b', 'c']
B = ['d', 'e']

for p in it.product(A, B):
    print p

# ('a', 'd')
# ('a', 'e')
# ('b', 'd')
# ('b', 'e')
# ('c', 'd')
# ('c', 'e')

for p in it.product(A, repeat = 3):
    print p

# ('a', 'a', 'a')
# ('a', 'a', 'b')
# ......
# ('c', 'c', 'b')
# ('c', 'c', 'c')

A = ['a', 'b', 'c', 'd', 'e']

for p in it.permutations(A):
    print p
# ('a', 'b', 'c', 'd', 'e')
# ('a', 'b', 'c', 'e', 'd')
# ......
# ('e', 'd', 'c', 'b', 'a')

for p in it.permutations(A, 3):
    print p

# ('a', 'b', 'c')
# ('a', 'b', 'd')
# ('a', 'b', 'e')
# ('a', 'c', 'b')
# ......
# ('e', 'd', 'c')

for p in it.combinations(A, 3):
    print p

# ('a', 'b', 'c')
# ('a', 'b', 'd')
# ('a', 'b', 'e')
# ('a', 'c', 'd')
# ('a', 'c', 'e')
# ('a', 'd', 'e')
# ......
# ('c', 'd', 'e')
