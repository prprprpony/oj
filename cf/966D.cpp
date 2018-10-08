#include<bits/stdc++.h>
using namespace std;
const int N = 312345;
vector<int> g[N],va;
bitset<N> vis;
int n,m,pa[N],de[N],ans;
void dfs(int u,vector<int> & w)
{
    w.push_back(u);
    vis[u] = 1;
    for (int v : g[u])
        if (!vis[v])
            dfs(v,w);
}
bool gao(int u)
{
    vector<int> w;
    dfs(u,w);
    for (int t : w)
        if (g[t].size() != w.size()) {
            ans = 5;
            for (int x : g[t])
                de[x] = 87;
            de[1] = de[t] = -87;
            for (int x : g[t])
                if (de[x] == 87) {
                    de[x] *= -1;
                    for (int y : g[x])
                        if (abs(de[y]) != 87) {
                            va = {1,t,x,y,t,n};
                            return true;
                        }
                }
        }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> q;
    q.push_back(1);
    fill_n(de+1,n,N);
    pa[1] = -1;
    de[1] = 0;
    for (int i = 0; i < q.size(); ++i) {
        int u = q[i];
        for (int v : g[u])
            if (!pa[v]) {
                pa[v] = u;
                de[v] = de[u] + 1;
                q.push_back(v);
            }
    }
    ans = de[n];
    if (ans <= 4) {
        for (int u = n; u > 0; u = pa[u])
            va.push_back(u);
        reverse(begin(va),end(va));
    } else {
        for (int u = 2; u < n; ++u)
            if (de[u] == 2) {
                va = {1,pa[u],u,1,n};
                ans = 4;
                break;
            }
        if (ans > 4) {       
            vis.reset();
            vis[1] = 1;
            for (int u : g[1])
                if (!vis[u] && gao(u))
                    break;
        }
    }
    if (ans == N) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
    for (int i = 0; i < va.size(); ++i)
        cout << va[i] << " \n"[i+1==va.size()];
}
