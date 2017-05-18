n, m = list(map(int, input().split()))
a = [[], [], []]
for i in range(n):
    w, c = list(map(int, input().split()))
    a[w-1].append(c)
p = [[0], [0], [0]]
for i in range(3):
    a[i].sort(reverse=True)
    for x in a[i]:
        p[i].append(p[i][-1] + x)
ans = 0
for i in range(min(m//3, len(a[2])) + 1):
    w = m - i * 3
    if len(a[1]) * 2 + len(a[0]) <= w:
        ans = max(ans, p[2][i] + p[1][len(a[1])] + p[0][len(a[0])])
        continue
    if not len(a[0]):
        ans = max(ans, p[2][i] + p[1][min(w//2, len(a[1]))])
        continue
    
    if 2 + 2 == 4:
        x = min(len(a[0]), w)
        y = (w - x) // 2
        ans = max(ans, p[2][i] + p[1][y] + p[0][x])

    lo = max((w - len(a[0]) + 1) // 2 + 1, 1)
    hi = min(len(a[1]), w // 2)
    while lo <= hi:
        mi = (lo + hi) // 2
        if a[1][mi - 1] - (p[0][w-mi*2+2] - p[0][w-mi*2]) > 0:
            lo = mi + 1
        else:
            hi = mi - 1
    ans = max(ans, p[2][i] + p[1][hi] + p[0][w-hi*2])
print(ans)
