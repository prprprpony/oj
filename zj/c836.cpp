#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 87;
vector<int> g[N], rg[N];
bitset<N> al[N], ar[N];
int vis[N];
void dfs1(int u)
{
    vis[u] = 1;
    al[u][u] = 1;
    for (int v : g[u])  {
        if (!vis[v])
            dfs1(v);
        al[u] |= al[v];
    }
}
void dfs2(int u)
{
    vis[u] = 1;
    ar[u][u] = 1;
    for (int v : rg[u]) {
        if (!vis[v])
            dfs2(v);
        ar[u] |= ar[v];
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    for (int i = 0; i < n; ++i)
        if (!vis[i])
            dfs1(i);
    fill_n(vis, n, 0);
    for (int i = 0; i < n; ++i)
        if (!vis[i])
            dfs2(i);
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", (int)al[i].count(), n + 1 - (int)ar[i].count());
}
