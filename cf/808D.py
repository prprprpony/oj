class Dick:
    def __init__(self):
        self.s = 0
        self.m = dict()
    def add(self, x):
        self.s += x
        if x in self.m:
            self.m[x] += 1
        else:
            self.m[x] = 1
    def rm(self, x):
        self.s -= x
        if self.m[x] > 1:
            self.m[x] -= 1
        else:
            self.m.pop(x)
    def shasei(self):
        return self.s
    def ininder(self, x):
        return x in self.m
def ok(a,n):
    w = sum(a)
    if w & 1:
        return 0
    f = Dick()
    s = Dick()
    for x in a:
        s.add(x)
    w //= 2
    for i in range(n):
        if s.ininder(w - f.shasei()) or f.ininder(w - s.shasei()):
            return 1
        f.add(a[i])
        s.rm(a[i])
    return 0

n = int(input())
a = list(map(int, input().split()))
print("YES" if ok(a,n) else "NO")
