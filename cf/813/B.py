x,y,l,r = list(map(int,input().split()))
a = []
f = 1
while f < r:
	g = 1
	while f + g <= r:
		if f + g >= l:
			a.append(f + g)
		g *= y
	f *= x
a += [l-1,r+1]
a.sort()
m = 1
for i in range(1,len(a)):
	if a[i-1] != a[i]:
		a[m] = a[i]
		m += 1
ans = 0
for i in range(1,m):
	ans = max(ans, a[i] - a[i-1] - 1)
print(ans)
