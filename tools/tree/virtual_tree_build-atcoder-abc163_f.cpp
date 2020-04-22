#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 87;
int n, c[N], lt[N], rt[N], tp, sz[N];
vector<int> g[N], g2[N];
vector<int> t[N];
void dfs(int u, int p)
{
    auto it = find(g[u].begin(), g[u].end(), p);
    if (it != end(g[u]))
        g[u].erase(it);
    lt[u] = tp++;
    sz[u] = 1;
    for (int v : g[u])  {
        dfs(v, u);
        sz[u] += sz[v];
    }
    rt[u] = tp;
}
bool in(int u, int v)
{
    return lt[v] <= lt[u] && rt[u] <= rt[v];
}
// 1-indexed
// add a new node 0 s.t. 0 is root
void build_g2(vector<int> & a)
{
    sort(a.begin(), a.end(), [&] (int i, int j) {return lt[i] < lt[j];});
    vector<int> st = {0};
    g2[0].clear();
    for (int u : a) {
        while (!in(u, st.back()))
            st.pop_back();
        g2[st.back()].push_back(u);
        st.push_back(u);
    }
}
ll gao(int u)
{
    ll ret = 0;
    int i = 0;
    ll s = g[u].size() ? sz[g[u][0]] : 0;
    for (int v : g2[u]) {
        while (i < g[u].size() && !in(v, g[u][i])) {
            ret += s * (s + 1) / 2;
            ++i;
            if (i < g[u].size())
                s = sz[g[u][i]];
        }
        s -= sz[v];
        ret += gao(v);
    }
    while (i < g[u].size()) {
        ret += s * (s + 1) / 2;
        ++i;
        if (i < g[u].size())
            s = sz[g[u][i]];
    }
    return ret;
}
ll solve(vector<int> & a)
{
    build_g2(a);
    return n * (n + 1ll) / 2 - gao(0);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[0].push_back(1);
    dfs(0, 0);
    for (int i = 1; i <= n; ++i)
        t[c[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
        cout << solve(t[i]) << '\n';
}
