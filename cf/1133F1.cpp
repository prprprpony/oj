#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2e5+87;
vector<int> g[N];
bool vis[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pii mx(-1,-1);
    for (int i = 1; i <= n; ++i)
        mx = max(mx, pii(g[i].size(),i));
    queue<int> q;
    q.push(mx.S);
    vis[mx.S] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u])
            if (!vis[v]) {
                cout << u << ' ' << v << '\n';
                vis[v] = 1;
                q.push(v);
            }
    }
}
