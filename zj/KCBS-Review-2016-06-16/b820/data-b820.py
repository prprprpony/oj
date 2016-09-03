#!/usr/bin/env python3
from random import *
T = 10
print(T)
for t in range(T):
    while True:
        a = [randint(0, 3), randint(0, 3)]
        if a[0] > 0 and a[1] > a[0]:
            continue
        a.append(3 - a[0])
        a.append(3 - a[1])
        if a[2] > 0 and a[3] > a[2]:
            continue
        break
    for v in a:
        print(v, end = ' ')
    print()
