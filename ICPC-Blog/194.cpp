#include<bits/stdc++.h>
using namespace std;
const int N = 7.5e5 + 87;
vector<int> g[N];
int c[N],d[N],p[N],r[N];
void dfs(int u,int v)
{
    p[v] = u;
    for (int w : g[v]) if (w != u) {
        dfs(v,w);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,1);
    while (q--) {
        int x;
        cin >> x;
        ++c[x];
        if (p[x])
            ++d[p[x]], ++r[p[x]];
        if (p[p[x]])
            ++d[p[p[x]]];
        cout << c[x] + d[x] + c[p[x]] + c[p[p[x]]] + (r[p[x]] ? r[p[x]] - c[x] : 0) << '\n';
    }
}
