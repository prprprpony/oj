#include<bits/stdc++.h>
using namespace std;
const int N = 4e4+87, Q = 1e5+88;
const int S = N/sqrt(Q); // best block size, time complexity O(N sqrt(Q))
int a[N],b[N];
vector<int> g[N];
int de[N],pa[N],hd[N],sz[N],et[N*2],en,lt[N],rt[N];
tuple<int,int,int,int,int> q[Q];
int cnt[N], SO_MANY_HW_WA_DA_FA[N], ca, ans[Q];
void FUKQTA(int i,int l,int r,int w)
{
    q[i] = {l/S,r,l,w,i};
}
void updcnt(int i,int x)
{
    int & c = cnt[i];
    int o = c;
    c += x;
    if ((c > 0) != (o > 0))
        ca += x;
}  
void upd(int u)
{
    int x = SO_MANY_HW_WA_DA_FA[u] ? -1 : 1;
    SO_MANY_HW_WA_DA_FA[u] ^= 1;
    updcnt(a[u],x);
}
void predfs(int p,int u)
{
    de[u] = de[p] + 1;
    pa[u] = p;
    sz[u] = 1;
    for (int & v : g[u])
        if (v == p) {
            v = g[u].back();
            g[u].pop_back();
            break;
        }
    for (int & v : g[u]) {
        predfs(u,v);
        sz[u] += sz[v];
        if (sz[v] > sz[g[u][0]])
            swap(v,g[u][0]);
    }
}
void hld(int u)
{
    et[lt[u] = en++] = u;
    if (hd[u] == 0)
        hd[u] = u;
    if (g[u].size())
        hd[g[u][0]] = hd[u];
    for (int v : g[u])
        hld(v);
    et[rt[u] = en++] = u;
}
int lca(int u,int v)
{
    while (hd[u] != hd[v]) {
        if (de[hd[u]] < de[hd[v]])
            v = pa[hd[v]];
        else
            u = pa[hd[u]];
    }
    return de[u] < de[v] ? u : v;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    copy_n(a+1,n,b);
    sort(b,b+n);
    int bn = unique(b,b+n) - b;
    for (int i = 1; i <= n; ++i) 
        a[i] = lower_bound(b,b+bn,a[i]) - b;
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    predfs(0,1);
    hld(1);
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        if (lt[u] > lt[v])
            swap(u,v);
        int w = lca(u,v);
        if (w == u)
            FUKQTA(i,lt[u],lt[v],0);
        else 
            FUKQTA(i,rt[u],lt[v],w);
    }
    sort(q,q+m);
    int l=0,r=-1;
    for (int i = 0; i < m; ++i) {
        int _,qr,ql,w,qi;
        tie(_,qr,ql,w,qi) = q[i];
        while (l > ql) upd(et[--l]);
        while (r < qr) upd(et[++r]);
        while (l < ql) upd(et[l++]);
        while (r > qr) upd(et[r--]);
        if (w) updcnt(a[w],1);
        ans[qi] = ca;
        if (w) updcnt(a[w],-1);
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << '\n';
}
