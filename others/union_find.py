#!/usr/bin/env python

from collections import deque
import itertools as ite
import sys
import math

sys.setrecursionlimit(1000000)

INF = 10 ** 18
MOD = 10 ** 9 + 7

n, q = map(int, raw_input().split())

# ｎ要素で初期化
par = [i for i in range(n + 1)]
rnk = [0 for i in range(n + 1)]

# 要素ｘの親を探す
def find(x):
    if par[x] == x:
        return x
    par[x] = find(par[x])
    return par[x]

def same(x, y):
    return find(x) == find(y)

# 要素ｘと要素ｙの属する集合を併合する
def unite(x, y):
    x_par = find(x)
    y_par = find(y)
    if x_par == y_par:
        return
    
    if rnk[x_par] < rnk[y_par]:
        par[x_par] = y_par
    else:
        par[y_par] = x_par
        if rnk[x_par] == rnk[y_par]:
            rnk[x_par] += 1

for loop in range(q):
    c, x, y = map(int, raw_input().split())
    if c == 0:
        unite(x, y)
    else:
        print int(same(x, y))