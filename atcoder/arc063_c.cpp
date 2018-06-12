#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87, inf = 1e9;
vector<int> g[N];
pii dp[N];
void dfs(int p,int u)
{
    for (int v : g[u]) if (v != p) {
        dfs(u,v);
        dp[u].F = max(dp[u].F,dp[v].F-1);
        dp[u].S = min(dp[u].S,dp[v].S+1);
    }
}
void go(int p,int u)
{
    dp[u].F = max(dp[u].F,dp[p].F-1);
    dp[u].S = min(dp[u].S,dp[p].S+1);
    for (int v : g[u]) if (v != p) {
        go(u,v);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill_n(dp+1,n,pii(-inf,inf));
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int v,p;
        cin >> v >> p;
        dp[v] = pii(p,p);
    }
    bool ok = 1;
    dfs(1,1);
    for (int i = 1; i <= n && ok; ++i)
        ok &= dp[i].F <= dp[i].S;
    go(1,1);
    for (int i = 1; i <= n && ok; ++i) {
        ok &= dp[i].F <= dp[i].S;
        for (int j : g[i])
            ok &= abs(dp[i].F - dp[j].F) == 1;
    }
    if (!ok) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i)
        cout << dp[i].F << '\n';
}
