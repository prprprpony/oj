#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+87;
int n,m,k,tp;
bool vis[N];
vector<int> g[N],ans[N];
void put(int u)
{
    if (ans[tp].size() == (2*n+k-1)/k)
        ++tp;
    ans[tp].push_back(u);
}
void dfs(int u)
{
    vis[u] = 1;
    put(u);
    for (int v : g[u])
        if (!vis[v]) {
            dfs(v);
            put(u);
        }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 0; i < k; ++i)
        if (ans[i].size()) {
            cout << ans[i].size();
            for (int j : ans[i])
                cout << ' ' << j;
            cout << '\n';
        } else {
            cout << "1 1\n";
        }
}
