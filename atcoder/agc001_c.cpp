#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2266;
vector<int> g[N];
vector<pii> e;
int vis[N], tt;
int dfs(int u, int d)
{
    if (!d)
        return 1;
    int ans = 1;
    for (int v : g[u]) if (vis[v] != tt) {
        vis[v] = tt;
        ans += dfs(v, d-1);
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        e.emplace_back(u,v);
    }
    int ans = 0;
    if (k & 1) {
        for (pii p : e) {
            ++tt;
            vis[p.F] = vis[p.S] = tt;
            ans = max(ans, dfs(p.F,k/2) + dfs(p.S,k/2));
        }
    } else {
        for (int u = 1; u <= n; ++u) {
            ++tt;
            vis[u] = tt;
            ans = max(ans, dfs(u,k/2));
        }
    }
    cout << n - ans << endl;
}
