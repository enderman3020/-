#!/usr/bin/env python

f = open('0013.txt', 'r')

ans = 0

for line in f:
    
    ans += long(line)
    

print ans

f.close()
