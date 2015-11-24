#!/usr/bin/env python
from random import *
f = open('929_data', 'w')
times = 1
n = 999
m = 999
buf = ""
buf += str(times) + '\n'
buf += str(n) + '\n'
buf += str(m) + '\n'
for t in range(times):
    for i in range(n):
        for j in range(m):
            buf += str(randint(0,9)) + ' '
        buf += '\n'
f.write(buf)
