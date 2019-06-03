#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+87;
int qry(int i,int u)
{
    cout << "ds"[i] << ' ' << u << endl;
    int x;
    cin >> x;
    if (x == -1)
        exit(0);
    return x;
}
vector<int> g[N],h[N];
int n,sz[N],hd[N];
void dfs(int p,int u)
{
    sz[u] = 1;
    for (int & v : g[u]) 
        if (v == p) {
            v = g[u].back();
            g[u].pop_back();
            break;
        }
    for (int & v : g[u]) {
        dfs(u,v);
        sz[u] += sz[v];
        if (sz[v] > sz[g[u][0]])
            swap(v,g[u][0]);
    }
}
void bld(int ph,int u)
{
    if (!ph) ph = u;
    hd[u] = ph;
    h[ph].push_back(u);
    for (int i = 0; i < g[u].size(); ++i)
        bld(i ? 0 : ph, g[u][i]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,1);
    bld(0,1);
    int u = 1, d = qry(0,1);
    while (d) {
        int r = qry(0,h[u].back());
        int k = h[u].size();
        // d-x + k-1-x = r
        int x = (d + k - 1 - r) / 2;
        u = h[u][x];
        d -= x;
        if (!d) break;
        u = qry(1,u);
        --d;
    }
    cout << "! " << u << endl; 
}
