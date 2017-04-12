from math import *
for kase in range(int(input())):
    n,k=[int(i) for i in input().split()]
    if n == 1:
        print(k)
        continue
    y = 10 * n - 1;
    g = gcd(k,y)
    k //= g
    y //= g
    a = 10 * k - y
    if a <= 0:
        print(0)
        continue
    temp = (10 * k * n + a - 1) // a
    m = 1
    v = 10
    while v < temp:
        m += 1
        v *= 10
    v %= y
    w = n % y
    vis = [False for i in range(y)]
    while v != w and not vis[v]:
        vis[v] = True;
        m += 1
        v = 10 * v % y
    if v == w:
        x = (10**m-n)//y*k
        print(x*10+k*g)
    else:
        print(0)
