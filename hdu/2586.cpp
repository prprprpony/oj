#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 87;
const int D = __lg(N) + 1;
vector<pair<int, int>> g[N];
int n, de[N], pa[N][D];
ll su[N];
void dfs(int u, int p, ll s)
{
    de[u] = de[p] + 1;
    su[u] = s;
    pa[u][0] = p;
    for (int i = 1; i < D; ++i)
        pa[u][i] = pa[pa[u][i - 1]][i - 1];
    for (auto e : g[u])
        if (e.first != p)
            dfs(e.first, u, s + e.second);
}
int lca(int a, int b)
{
    if (de[b] > de[a])
        swap(a, b);
    for (int d = de[a] - de[b], k = 0; d; d >>= 1, ++k)
        if (d & 1)
            a = pa[a][k];
    if (a == b)
        return a;
    for (int k = D - 1; k >= 0; --k)
        if (pa[a][k] != pa[b][k]) {
            a = pa[a][k];
            b = pa[b][k];
        }
    return pa[a][0];
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            g[x].emplace_back(y, d);
            g[y].emplace_back(x, d);
        }
        dfs(1, 0, 0);
        while (q--) {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%lld\n", su[a] + su[b] - 2 * su[lca(a, b)]);
        }
    }

}
