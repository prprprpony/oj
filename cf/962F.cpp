#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
vector<int> g[N], e, bcc[N];
int tin[N], dfn, low[N], st[N], tp, bcid;
bool vis[N];
void dfs(int p,int u)
{
    low[u] = tin[u] = ++dfn;
    for (int i : g[u]) {
        int v = e[i];
        if (v == p)
            continue;
        if (!vis[i>>1]) {
            vis[i>>1] = 1;
            st[tp++] = i>>1;
        }
        if (!tin[v]) {
            dfs(u,v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u]) {
                int k = bcid++, t;
                do {
                    t = st[--tp];
                    bcc[k].push_back(t);
                } while (t != (i>>1));
            }
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        e.push_back(u);
        e.push_back(v);
        g[v].push_back(i*2);
        g[u].push_back(i*2+1);
    }
    for (int i = 1; i <= n; ++i) {
        if (!tin[i]) {
            dfs(0,i);
        }
    }
    int * cnt = low;
    vector<int> ans;
    for (int i = 0; i < bcid; ++i) {
        if (bcc[i].size() == 1)
            continue;
        for (int j : bcc[i])
            cnt[e[j<<1]] = cnt[e[j<<1|1]] = 0;
        bool ok = 1;
        for (int j : bcc[i]) {
            ok &= ++cnt[e[j<<1]] <= 2;
            ok &= ++cnt[e[j<<1|1]] <= 2;
        }
        if (ok) { 
            for (int x : bcc[i])
                ans.push_back(x);
        }
    }
    sort(begin(ans),end(ans));
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i+1 << " \n"[i == ans.back()];
    if (!ans.size())
        cout << '\n';
}
