#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 87;
const int D = __lg(N) + 1;
vector<pair<int, int>> g[N];
int n, de[N], pa[N][D], mx[N][D];
void dfs(int u, int p, int d)
{
    de[u] = de[p] + 1;
    pa[u][0] = p;
    mx[u][0] = d;
    for (int i = 1; i < D; ++i)  {
        pa[u][i] = pa[pa[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[pa[u][i - 1]][i - 1]);
    }
    for (auto e : g[u])
        if (e.first != p)
            dfs(e.first, u, e.second);
}
pair<int, int> lca(int a, int b)
{
    int m = 0;
    if (de[b] > de[a])
        swap(a, b);
    for (int d = de[a] - de[b], k = 0; d; d >>= 1, ++k)
        if (d & 1)  {
            m = max(m, mx[a][k]);
            a = pa[a][k];
        }
    if (a == b)
        return {a, m};
    for (int k = D - 1; k >= 0; --k)
        if (pa[a][k] != pa[b][k]) {
            m = max({m, mx[a][k], mx[b][k]});
            a = pa[a][k];
            b = pa[b][k];
        }
    return {pa[a][0], max({m, mx[a][0], mx[b][0]})};
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        g[x].emplace_back(y, d);
        g[y].emplace_back(x, d);
    }
    dfs(1, 0, 0);
    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b).second);
    }
        
}
