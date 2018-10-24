#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
const int M = N * 2;
int n,a[N],b[N],f[M];
void add(int i)
{
    for (; i < M; i += i & -i)
        ++f[i];
}
int qry(int i)
{
    int r=0;
    for (; i ; i ^= i & -i)
        r += f[i];
    return r;
}
bool ok(int k)
{
    memset(f,0,sizeof(f));
    int s = N;
    add(s);
    long long t = (n * (n + 1LL) / 2 + 1) / 2;
    for (int i = 1; i <= n; ++i) {
        s += a[i] >= k ? 1 : -1;
        t -= qry(s);
        add(s);
    }
    return t <= 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    copy_n(a+1,n,b);
    sort(b,b+n);
    int bn = unique(b,b+n) - b, ans = 0;
    for (int k = 1<<__lg(bn); k; k >>= 1)
        if ((ans | k) < bn && ok(b[ans | k]))
            ans |= k;
    cout << b[ans] << '\n';
}
