ans = []
a,b = 1, 0
for i in range(1001):
    ans.append(a+b)
    if i % 2 == 0:
        a, b = a, a+b
    else:
        a, b = a+b, b
try:
    while True:
        n = int(input())
        print(ans[n])
except EOFError:
    pass
