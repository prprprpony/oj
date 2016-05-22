#!/bin/env python3
from random import *
T = 100
MAXN = 100
for t in range(T):
    #N = randint(1, MAXN)
    N = MAXN
    print(N)
    for i in range(N):
        for j in range(N):
            print(randint(1, 100), end=' ')
        print()
print(0)
