#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87;
const int D = __lg(N) + 1;
vector<int> g[N];
int n,q,tin[N],dfn,de[N],pa[N][D];
struct seg
{
    array<int,2> mx,mn;
    seg operator + (const seg & r) const
    {
        seg ret;

        vector<int> p;
        for (int i : mx) if (i) p.push_back(i);
        for (int i : r.mx) if (i) p.push_back(i);
        sort(begin(p),end(p),[&](int i,int j)->bool{return tin[i] > tin[j];});
        for (int i = 0; i <= 1; ++i) ret.mx[i] = p[i];

        p.clear();
        for (int i : mn) if (i) p.push_back(i);
        for (int i : r.mn) if (i) p.push_back(i);
        sort(begin(p),end(p),[&](int i,int j)->bool{return tin[i] < tin[j];});
        for (int i = 0; i <= 1; ++i) ret.mn[i] = p[i];
        return ret;
    }
} t[N*4];
void dfs(int p,int u) 
{
    de[u] = de[p] + 1;
    pa[u][0] = p;
    for (int i = 1; i < D; ++i)
        pa[u][i] = pa[pa[u][i-1]][i-1];
    tin[u] = ++dfn;    
    for (int v : g[u])
        dfs(u,v);
}
void bld(int o=1,int l=1,int r=n+1)
{
    if (r - l == 1) {
        t[o] = {{l,0},{l,0}};
        return;
    }
    int m = l + (r - l) / 2;
    bld(o<<1,l,m);
    bld(o<<1|1,m,r);
    t[o] = t[o<<1] + t[o<<1|1];
}
seg qry(int i,int j,int o=1,int l=1,int r=n+1)
{
    if (i <= l && r <= j)
        return t[o];
    int m = l + (r - l) / 2;
    if (j <= m)
        return qry(i,j,o<<1,l,m);
    if (i >= m)
        return qry(i,j,o<<1|1,m,r);
    return qry(i,j,o<<1,l,m) + qry(i,j,o<<1|1,m,r);
}
int lca(int u,int v) 
{
    if (!u || !v) return u ? u : v;
    if (de[v] > de[u])
        swap(u,v);
    for (int k = 0, d = de[u] - de[v]; d; ++k, d>>=1)
        if (d&1)
            u = pa[u][k];
    if (u == v)
        return u;
    for (int k = D-1; k >= 0; --k)
        if (pa[u][k] != pa[v][k]) {
            u = pa[u][k];
            v = pa[v][k];
        }
    return pa[u][0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    dfs(0,1);
    bld();
    while (q--) {
        int l,r;
        cin >> l >> r;
        auto s = qry(l,r+1);
        pii ans = max(
            pii(de[lca(s.mn[0],s.mx[1])], s.mx[0]),
            pii(de[lca(s.mx[0],s.mn[1])], s.mn[0])
        );
        cout << ans.S << ' ' << ans.F-1 << '\n';
    }
}
