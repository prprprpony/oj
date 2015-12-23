#!/bin/env python
from random import *
k = 100000
f = open('data', 'w')
f.write(str(k) + ' 426\n')
for times in range(2):
    for i in range(k):
        f.write(str(randint(0, k)) + ' ')
    f.write('\n')
