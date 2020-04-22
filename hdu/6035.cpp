#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 87;
int c[N], su[N], sz[N], vis[N];
ll ans;
vector<int> g[N];
void dfs(int u, int p)
{
    sz[u] = 1;
    int chadd = 0;
    for (int v : g[u])
        if (v != p) {
            ll pre = su[c[u]];
            dfs(v, u);
            ll add = su[c[u]] - pre;
            ll tmp = sz[v] - add;
            ans -= tmp * (tmp - 1) / 2;
            chadd += add;
            sz[u] += sz[v];
        }
    su[c[u]] += sz[u] - chadd;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
            vis[i] = su[i] = 0;
            g[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ans = 0;
        dfs(1, 1);
        for (int i = 1; i <= n; ++i)
            if (vis[c[i]] == 0) {
                vis[c[i]] = 1;
                ll tmp = n - su[c[i]];
                ans += n * (n - 1ll) / 2 - tmp * (tmp - 1) / 2;
            }
        static int kase = 0;
        cout << "Case #" << ++kase << ": " << ans << '\n';
    }
}
