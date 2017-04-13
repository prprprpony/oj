N = 1001;
f=[0,1]
for i in range(2,N):
    f += [2 * f[i-2] + 3]
    j = 0
    while j <= i - 1 and 2**j < f[i]:
        f[i] = min(f[i], 2*(2**j - 1 + f[i-1-j]) +1)
        j += 1
kase=0
try:
    while True:
        n = int(input())
        kase += 1
        print("Case ",kase,": ",f[n],sep='')
except EOFError:
    pass
