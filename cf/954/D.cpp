#include<bits/stdc++.h>
using namespace std;
const int N = 1024, inf = 0x3f3f3f3f;
bitset<N> g[N];
int ds[N], dt[N];
void go(int u,int n,int d[])
{
    memset(d+1,0x3f,sizeof(d[1]) * n);
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        u = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
            if (g[u][i] && d[i] == inf) {
                d[i] = d[u] + 1;
                q.push(i);
            }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    go(s,n,ds);
    go(t,n,dt);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            ans += !g[i][j] && min(ds[i] + dt[j], ds[j] + dt[i]) + 1 >= ds[t];
    cout << ans << endl;
}
