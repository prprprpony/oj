#include<bits/stdc++.h>
using namespace std;
const int N = 505, inf = 0x3f3f3f3f, R = 200200;
int g[N][N], ans[R], ok[N];
pair<int, int> a[N];
tuple<int, int, int, int> qry[R];
int main()
{
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);
    memset(g, inf, sizeof g);
    for (int i = 0, x; i < n; ++i) {
        scanf("%d", &x);
        a[i] = {x, i};
    }
    for (int i = 0; i < m; ++i) {
        int s, t, c;
        scanf("%d%d%d", &s, &t, &c);
        --s, --t;
        g[s][t] = g[t][s] = min(g[s][t], c);
    }
    for (int i = 0; i < r; ++i) {
        int f, u, v;
        scanf("%d%d%d", &f, &u, &v);
        --u, --v;
        qry[i] = {f, i, u, v};
    }
    sort(a, a + n);
    sort(qry, qry + r);
    int x = n;
    for (int y = r - 1; y >= 0; --y) {
        int f, ai, u, v;
        tie(f, ai, u, v) = qry[y];
        while (x - 1 >= 0 && a[x - 1].first >= f) {
            int k = a[--x].second;
            ok[k] = 1;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
        ans[ai] = !ok[u] || !ok[v] || g[u][v] == inf ? -1 : g[u][v];
    }
    for (int i = 0; i < r; ++i)
        cout << ans[i] << "\n";
}
