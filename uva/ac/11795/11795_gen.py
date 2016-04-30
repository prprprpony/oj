T = 1
N = 16
print(T)
for t in range(T):
    print(N)
    for i in range(N + 1):
        for j in range(N):
            print(1, end = '')
        print()
