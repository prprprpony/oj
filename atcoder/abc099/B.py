a,b = map(int,input().split())
k = b - a
w = k * (1 + k) // 2
print(w - b)
