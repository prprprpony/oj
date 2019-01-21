#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
typedef pair<int,int> pii;
#define F first
#define S second
int n,m,vis[N],s[N],tp;
pair<pii,int> e[N];
vector<int> g[N];
bool dfs(int u)
{
//    cerr << "dfs " << u << ' ' << vis[u]<< endl;
    if (vis[u] == 1)
        return 1;
    if (vis[u] == 2)
        return 0;
    vis[u] = 1;
    for (int v : g[u])
        if (dfs(v))
            return 1;
    vis[u] = 2;
    return 0;
}
void topo(int u)
{
    if (vis[u])
        return;
    for (int v : g[u])
        topo(v);
    s[vis[u] = tp--] = u;
}
bool ok(int k)
{
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int i = 1; i <= m; ++i) 
        if (e[i].S > k) {
            int u,v;
            tie(u,v) = e[i].F;
            g[u].push_back(v);
        }
    //cerr << "ok " << k << endl;
    fill_n(vis,n+1,0);
    for (int i = 1; i <= n; ++i)
        if (!vis[i] && dfs(i))
            return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> e[i].F.F >> e[i].F.S >> e[i].S;
    int lo = 0, hi = 1e9;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (ok(mi))
            hi = mi - 1;
        else
            lo = mi + 1;
    }
    assert( ok(lo) );
    fill_n(vis,n+1,0);
    tp = n;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            topo(i);
    vector<int> ans;
    for (int i = 1; i <= m; ++i)
        if (e[i].S <= lo && vis[e[i].F.F] > vis[e[i].F.S])
            ans.push_back(i);
    cout << lo << ' ' << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i+1==ans.size()];
}
