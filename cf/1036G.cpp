#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
vector<int> g[N],sc,si;
int in[N],out[N],ma[N];
int dfs(int u)
{
    if (ma[u] != -1)
        return ma[u];
    ma[u] = 0;
    for (int v : g[u])
        ma[u] |= dfs(v);
    return ma[u];
}
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
        ++out[u];
        ++in[v];
    }
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0)
            sc.push_back(i);
        if (out[i] == 0)
            si.push_back(i);
    }
    memset(ma,-1,sizeof(ma));
    for (int i = 0; i < si.size(); ++i)
        ma[si[i]] = 1<<i;
    for (int i = 0; i < sc.size(); ++i)
        dfs(sc[i]);
    for (int s = 1; s < (1<<sc.size())-1; ++s) {
        int t = 0;
        for (int k = 0, w = s; w; w>>=1,++k)
            if (w&1)
                t |= ma[sc[k]];
        if (__builtin_popcount(s) >= __builtin_popcount(t)) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
