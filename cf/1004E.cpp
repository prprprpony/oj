#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87;
vector<pii> g[N],dia;
pii md;
int n,k,pa[N],vis[N],vc;
void dfs(int p,int u,int d = 0)
{
    pa[u] = p;
    vis[u] = vc;
    md = max(md, pii(d,u));
    for (const auto & v : g[u]) 
        if (vis[v.F] != vc)
            dfs(u,v.F,d+v.S);
}
int ck(int l,int r)
{
    l = max(0,l);
    r = min((int)dia.size()-1,r);
    if (l > r || r - l + 1 > k)
        return INT_MAX;
    ++vc;
    for (int i = l; i <= r; ++i)
        vis[dia[i].F] = vc;
    md = {-1,-1};
    for (int i = l; i <= r; ++i)
        dfs(0,dia[i].F);
    return md.F;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    md = {-1,-1};
    ++vc;
    dfs(0,1);
    int a = md.S;
    md = {-1,-1};
    ++vc;
    dfs(0,a);
    int b = md.S;
    dia.emplace_back(b,0);
    for (int u = b; u != a; u = pa[u])
        for (const auto & v : g[u])
            if (v.F == pa[u])
                dia.emplace_back(v);
    int l = 0, r = dia.size() - 1,  ls = 0, rs = 0;
    while (r - l + 1 > k) {
        if (ls < rs)
            ls += dia[++l].S;
        else 
            rs += dia[r--].S;
    }
//    for (auto p : dia) cerr << p.F << ' ' << p.S << endl; 
    int ans = INT_MAX;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            ans = min(ans, ck(l+i,r+j));
    cout << ans << '\n';
}
