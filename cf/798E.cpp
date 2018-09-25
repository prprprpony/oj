#include<bits/stdc++.h>
using namespace std;
const int N = 5.1e5;
int n,a[N],b[N],t[N*4];
int hao(int i,int j)
{
    return a[i] < a[j] ? j : i;
}
void init(int o=1,int l=1,int r=n+1)
{
    if (r - l == 1) {
        t[o] = l;
        return;
    }
    int m = l + (r - l) / 2;
    init(o<<1,l,m);
    init(o<<1|1,m,r);
    t[o] = hao(t[o<<1],t[o<<1|1]);
}
void upd(int i,int v,int o=1,int l=1,int r=n+1)
{
    if (r - l == 1) {
        t[o] = v;
        return;
    }
    int m = l + (r - l) / 2;
    if (i < m)
        upd(i,v,o<<1,l,m);
    else
        upd(i,v,o<<1|1,m,r);
    t[o] = hao(t[o<<1],t[o<<1|1]);
}
int qry(int i,int j,int o=1,int l=1,int r=n+1)
{
    if (r <= i || j <= l)
        return 0;
    if (i <= l && r <= j)
        return t[o];
    int m = l + (r - l) / 2;
    return hao(qry(i,j,o<<1,l,m),qry(i,j,o<<1|1,m,r));
}
int st[N],tp,p[N];
void dfs(int u)
{
    if (u <= 0 || u > n || !a[u])
        return;
    upd(u,0);
    dfs(a[u]);
    a[u] = 0;
    int v;
    while (a[v = qry(1,b[u])] > u)
        dfs(v);
    st[tp++] = u;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > 0)
            b[a[i]] = i;
        else
            a[i] = n+1;
    }
    for (int i = 1; i <= n; ++i)
        if (!b[i])
            b[i] = n+1;
    init();
    for (int i = 1; i <= n; ++i)
        dfs(i);
    for (int i = 0; i < n; ++i)
        p[st[i]] = n-i;
    for (int i = 1; i <= n; ++i)
        cout << p[i] << " \n"[i==n];
}
