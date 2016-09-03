#include <cstdio>
#include <algorithm>
using namespace std;
struct person
{
    double a, b, c;
    int r;
    bool operator < (const person & x) const
    {
        if ((a + b) != (x.a + x.b))
            return (a + b) < (x.a + x.b);
        if (a != x.a)
            return a < x.a;
        return b < x.b;
    }
};
struct cmp
{
    bool operator () (const person & a, const person & b) const
    {
        return a.c < b.c;
    }
};
const int maxn = 1.228e5;
int n;
person p[maxn];

int bit[maxn]; // [1, n]
int lowbit(int x) {return x & -x;}
void add(int i, int v)
{
    for ( ; i <= n; i += lowbit(i))
        bit[i] += v;
}

long long sum(int i)
{
    long long ret = 0;
    for ( ; i; i ^= lowbit(i))
       ret += bit[i];
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf%lf", &p[i].a, &p[i].b, &p[i].c);
    sort(p + 1, p + 1 + n, cmp());
    for (int i = 1; i <= n; ++i)
        p[i].r = i;
    sort(p + 1, p + 1 + n);
    long long ans = 0;
    for (int i = n; i >= 1; --i) {
        ans += sum(p[i].r - 1);
        add(p[i].r, 1);
    }
    printf("%lld\n", ans);
}
