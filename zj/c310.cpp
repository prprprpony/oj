#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 87;
int n, lt[N], rt[N], dfn, f[N];
vector<int> g[N];
void dfs(int u)
{
    lt[u] = ++dfn;
    for (int v : g[u])
        dfs(v);
    rt[u] = dfn;
}
void add(int i, int v)
{
    for (; i < N; i += i & -i)
        f[i] += v;
}
int qry(int i)
{
    int r = 0;
    for (; i > 0; i -= i & -i)
        r += f[i];
    return r;
}
int qry(int i, int j)
{
    return qry(j) - qry(i - 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y)
            swap(x, y);
        g[x].push_back(y);
    }
    dfs(1);
    fill_n(f, n + 1, 0);
    for (int i = 1; i <= n; ++i)
        add(i, 1);
    int q;
    scanf("%d", &q);
    while (q--) {
        int c, x;
        scanf("%d%d", &c, &x);
        if (c == 1) {
            int y = qry(lt[x], lt[x]);
            add(lt[x], 1 - 2 * y);
        } else {
            printf("%d\n", qry(lt[x], rt[x]));
        }
    }
}
