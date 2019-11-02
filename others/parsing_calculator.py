#!/usr/bin/env python

from collections import deque
import itertools as it
import sys
import math
import re

sys.setrecursionlimit(1000000)

# calculator with "1234567890()+-*/"

# evaluate operation
def operate(term1, term2, op):
    if op == '+':
        return term1 + term2
    if op == '-':
        return term1 - term2
    if op == '*':
        return term1 * term2
    if op == '/':
        return term1 / term2
    # case of integer:
    if op == '/':
        if term1 * term2 < 0 and term1 % term2 != 0:
            return term1 / term2 + 1
        else:
            return term1 / term2

# evaluate expression without bracket
def calc(S):
    print S
    if len(S) == 1:
        if type(S[0]) == type(""):
            return int(S[0])
        else:
            return S[0]
    for i in range(len(S) - 1, -1, -1):
        if S[i] in ['+', '-']:
            return operate(calc(S[:i]), calc(S[i + 1:]), S[i])
    return operate(calc(S[:-2]), calc(S[-1:]), S[-2]) # case of ['*', '/']

# evaluate expression
def br(S):
    index = 0
    lst = []
    while True:
        if index >= len(S) or S[index] == ')':
            return index, calc(lst)
        elif S[index] == '(':
            ret, value = br(S[index + 1:])
            index += ret + 1
            lst.append(value)
        else:
            lst.append(S[index])
        index += 1

# "-(11+22)" -> ['-1', '*', '(', '11', '+', '22', ')']
def split(S):
    ret = ['?']
    c_num = "1234567890"
    for c in S:
        if c in c_num and ret[-1][-1] in c_num:
            ret[-1] += c
        elif c == '-' and not ret[-1][-1] in c_num + ')': # string of term must end with "1234567890)"
            ret.append('-1')
            ret.append('*')
        else:
            ret.append(c)
    return ret[1:]

while True:
    S = raw_input()
    #S.replace(' ', '')
    print br(split(S))[1]