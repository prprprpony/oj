#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define ALL(a) begin(a), end(a)
const int N = 205;
vector<int> g[N];
bitset<N> vis;
int a[4];
bool dfs(int i,int u)
{
    a[i] = u;
    vis[u] = 1;
    if (i == 3) { 
        if (count(ALL(g[u]),a[0]))
            return 1;
    } else {
        for (int v : g[u]) {
            if (vis[v])
                continue;
            if (dfs(i+1,v))
                return 1;
        }
    }
    vis[u] = 0;
    return 0;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        g[i].clear();
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) 
        if (g[i].size() != 3){
            cout << "-1\n";
            return;
        }
    vis.reset();
    if (!dfs(0,0)) {
        cout << "-1\n";
        return;
    }
    bool f=0;
    for (int x : g[a[0]]) if (!vis[x])
        for (int y : g[a[1]]) if (!vis[y])
            if (count(ALL(g[x]),y))
                f=1;
    vector<pii> v;
    if (f) {
        v.push_back({a[0],a[1]});
        v.push_back({a[3],a[2]});
    } else {
        v.push_back({a[0],a[3]});
        v.push_back({a[1],a[2]});
    }
    for (int i = 3; i <= n/2; ++i) {
        int l = v.back().F, r = v.back().S;
        for (int x : g[l]) if (!vis[x])
            for (int y : g[r]) if (!vis[y])
                if (count(ALL(g[x]),y)) {
                    vis[x] = 1;
                    vis[y] = 1;
                    v.push_back({x,y});
                    goto nxt;
                }
nxt:
        if (v.size() != i) {
            cout << "-1\n";
            return;
        }
    }
    if (!(count(ALL(g[v.back().F]),v[0].F) && count(ALL(g[v.back().S]),v[0].S))) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n/2; ++i) cout << v[i].F << ' ';
    for (int i = 0; i < n/2; ++i) cout << v[i].S << " \n"[i==n/2-1];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}
