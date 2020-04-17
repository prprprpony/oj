#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 87;
int n, m, t[N], s[N], f[N];
void add(int i, int v)
{
    for (; i < N; i += i & -i)
        f[i] += v;
}
int qry(int i)
{
    int r = 0;
    for (; i > 0; i -= i & -i)
        r += f[i];
    return r;
}
int qry(int i, int j)
{
    return qry(j) - qry(i - 1);
}
void init()
{
    fill_n(f, m + 1, 0);
    for (int i = 1; i <= m; ++i)
        add(i, 1);
}
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    init();
    int la = -1;
    for (int i = 0; i < n; ++i) {
        if (qry(t[i] + 1, m))
            la = i;
        if (!qry(t[i], t[i]))
            break;
        add(t[i], -1);
    }
    init();
    for (int i = 0; i < la; ++i) {
        s[i] = t[i];
        add(t[i], -1);
    }
    int x;
    for (x = t[la] + 1; x <= m && qry(x, x) == 0; ++x);
    s[la] = x;
    add(x, -1);
    for (int i = la + 1, j = 1; i < n; ++i) {
        while (qry(j, j) == 0)
            ++j;
        s[i] = j;
        add(j, -1);
    }
    for (int i = 0; i < n; ++i)
        printf("%d%c", s[i], " \n"[i == n - 1]);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
}
