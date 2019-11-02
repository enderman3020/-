#!/usr/bin/env python

piyo = 2 ** 1000

piyo_str = str(piyo)

sum = 0

for c in piyo_str:
    sum += int(c)

print sum

