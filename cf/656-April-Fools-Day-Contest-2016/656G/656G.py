#kitten
r = range
p = input
c = [0] * 10
f, n, t = map(int, p().split())
for i in r(f):
    b = p()
    for j in r(n):
        if b[j] == 'Y':
            c[j] += 1
a = 0
for j in r(n):
    if c[j] >= t:
        a += 1
print(a)
