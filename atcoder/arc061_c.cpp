#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int C = 1e6 + 87, N = 4e5;
int tp, tt, vis[N];
vector<pii> e[C];
vector<int> g[N],tg[N];
void dfs(int u)
{
    g[u].push_back(tp);
    g[tp].push_back(u);
    vis[u] = tt;
    for (int v : tg[u])
        if (vis[v] != tt) {
            dfs(v);
        }
}
int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    tp = n;
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        e[c].emplace_back(a,b);
    }
    for (int c = 0; c < C; ++c) {
        for (auto x : e[c])  {
            tg[x.F].clear();
            tg[x.S].clear();
        }
        for (auto x : e[c])  {
            tg[x.F].push_back(x.S);
            tg[x.S].push_back(x.F);
        }
        ++tt;
        for (auto x : e[c])  {
            if (vis[x.F] != tt) {
                ++tp;
                dfs(x.F);
            }
        }
    }
    ++tt;
    vector<int> q[2];
    q[0] = {1};
    vis[1] = tt;
    int d = 0;
    for (int i = 0; q[i].size() && vis[n] != tt; ++d, i^=1) {
        q[i^1].clear();
        for (int u : q[i])
            for (int v : g[u])
                if (vis[v] != tt) {
                    vis[v] = tt;
                    q[i^1].push_back(v);
                }
    } 
    if (vis[n] != tt) {
        cout << "-1\n";
        return 0;
    }
    cout << d/2 << endl;
}
