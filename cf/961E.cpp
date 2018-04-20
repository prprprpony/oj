#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87;
int a[N],f[N],p[N];
void add(int i,int v)
{
    for (; i < N; i += i & -i)
        f[i] += v;
}
int qry(int i)
{
    int r = 0;
    for (; i; i ^= i & -i)
        r += f[i];
    return r;
}
void rm(int i)
{
    if (qry(i) - qry(i-1))
        add(i,-1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    iota(p+1,p+n+1,1);
    sort(p+1,p+n+1,[&](int i,int j)->bool{return a[i]<a[j];});
    int tp = 1;
    for (int i = 1; i <= n; ++i)
        add(i,1);
    for (int i = 1; i <= n; ++i) {
        rm(i);
        while (tp <= n && a[p[tp]] < i)
            rm(p[tp++]);

        ans += qry(min(n, a[i]));
    }
    cout << ans << endl;
}
