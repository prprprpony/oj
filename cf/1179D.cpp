#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+87;
const ll inf = 9e18;
struct line
{
    ll a,b;
    bool operator == (const line & x) const
    {
        return a==x.a&&b==x.b;
    }
    ll operator () (ll x)
    {
        return a * x + b;
    }
} t[N],I={0,inf};
ll n,sz[N],dp[N],ans;
void clr(int l=1,int r=n)
{
    if (r < l)
        return;
    int m = (l+r)/2;
    if (t[m] == I)
        return;
    t[m] = I;
    clr(l,m-1);
    clr(m+1,r);
}
void upd(line f)
{
    int l=1,r=n;
    while (l <= r) {
        int m = (l+r)/2;
        if (f(m) < t[m](m))
            swap(t[m],f);
        if (f(l) < t[m](l))
            r = m-1;
        else if (f(r) < t[m](r))
            l = m+1;
        else
            break;
    }
}
ll qry(ll x)
{
    ll ret=inf;
    int l=1,r=n;
    while (l <= r) {
        int m = (l+r)/2;
        ret = min(ret, t[m](x));
        if (x < m)
            r = m-1;
        else if (x > m)
            l = m+1;
        else
            break;
    }
    return ret;
}
vector<int> g[N];
void dfs(int u,int p)
{
    for (int & v : g[u])
        if (v == p) {
            v = g[u].back();
            g[u].pop_back();
            break;
        }
    sz[u] = 1;
    for (int v : g[u]) {
        dfs(v,u);
        sz[u] += sz[v];
    }
}
void gao(int u)
{
    dp[u] = sz[u] * sz[u];
    for (int v : g[u]) {
        gao(v);
        dp[u] = min(dp[u], (sz[u] - sz[v]) * (sz[u] - sz[v]) + dp[v]);
    }
    clr();
    for (int v : g[u]) {
        ans = min(qry(sz[v]) + sz[v] * sz[v] + dp[v],ans);
        // (n-x-y)^2 + dx + dy
        // = (n-y)^2-2x(n-y)+x^2+dx+dy
        // = -2(n-y) x + (n-y)^2 + dy + x^2 + dx
        upd({-2*(n-sz[v]), (n-sz[v])*(n-sz[v]) + dp[v]});
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    ans = inf;
    gao(1);
    ans = min(ans, dp[1]);
    cout << (n*n-ans + n * (n-1))/2 << endl;
}
