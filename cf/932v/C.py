def exgcd(a,b):
    if b > 0:
        y,x,g = exgcd(b,a%b)
        y -= a//b * x
        return x,y,g
    else:
        return 1,0,a
n,a,b = map(int,input().split())
x0,y0,g = exgcd(a,b)
if n % g != 0:
    print(-1)
    exit(0)
a //= g
b //= g
k = n//g
#print(a,x0,b,y0,g)
r = k * x0 // b
l = (k * -y0 + a - 1) // a
if l > r:
    print(-1)
    exit(0)
x = k * x0 - b * l
y = k * y0 + a * l
a *= g
b *= g
#print(a,x,b,y,n)
for i in range(x):
    for j in range(a-1):
        print(i*a + j + 2,end=' ')
    print(i*a+1,end=' ')
for i in range(y):
    for j in range(b-1):
        print(x*a + i*b + j + 2,end=' ')
    print(x*a + i*b+1,end=' ')
print()
