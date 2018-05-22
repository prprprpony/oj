#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 3056, Q = 4e5 + 87;
vector<int> g[N];
vector<pii> qry[N][N];
int ans[Q];
int st[N], tp, vis[N], tt, on[N], mutom;
void dfs(int u)
{
    if (vis[u] == tt) {
        if (on[u] != -1)
            mutom = min(mutom, on[u]);
        return;
    }
    vis[u] = tt;
    on[u] = tp;
    st[tp++] = u;
    for (const pii & q : qry[st[0]][u]) {
        int i,k;
        tie(i,k) = q;
        ans[i] = k >= tp || tp-1 >= mutom ? -1 : st[k];
    }
    qry[st[0]][u].clear();
    for (int v : g[u])
        dfs(v);
    on[u] = -1;
    --tp;
    if (tp == mutom)
        mutom = N;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    for (int i = 0; i < n; ++i)
        sort(begin(g[i]),end(g[i]));
    for (int i = 0; i < q; ++i) {
        int s, t, k;
        cin >> s >> t >> k;
        --s, --t, --k;
        qry[s][t].emplace_back(i,k);
    }
    fill_n(on,n,-1);
    for (int i = 0; i < n; ++i) {
        mutom = N;
        ++tt;
        dfs(i);
        for (int j = 0; j < n; ++j)
            for (const pii & p : qry[i][j])
                ans[p.F] = -1;
    }
    for (int i = 0; i < q; ++i)
        cout << (ans[i] == -1 ? -1 : ans[i] + 1) << '\n';
}
