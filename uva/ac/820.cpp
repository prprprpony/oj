#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
const int inf = 2147483647;
int n;
int cap[maxn][maxn];
int flow[maxn][maxn];
vector<int> G[maxn];
int a[maxn];
int p[maxn];
void Init()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cap[i][j] = flow[i][j] = 0;
        G[i].clear();
    }
}
inline int Residual(int from, int to)
{
    // return flow[from][to] < 0 ? -flow[from][to] : cap[from][to] - flow[from][to];
    return cap[from][to] - flow[from][to];
}
int MaxFlow(int s, int t)
{
    int maxflow = 0;
    while (1) {
        memset(a + 1, 0, n * sizeof(int));
        memset(p + 1, 0, n * sizeof(int));
        a[s] = inf;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (vector<int>::iterator it = G[x].begin(); it != G[x].end(); it++)
                if (!a[*it] && Residual(x, *it)) {
                    a[*it] = min(a[x], Residual(x, *it));
                    p[*it] = x;
                    q.push(*it);
                }
            if (a[t])
                break;
        }
        if (!a[t])
            break;
        maxflow += a[t];
        for (int u = t; u != s; u = p[u]) {
            flow[p[u]][u] += a[t];
            flow[u][p[u]] -= a[t];
        }
    }
    return maxflow;
}
int main()
{
    int s, t, k;
    int u, v, c;
    int kase = 0;
    while (cin >> n && n) {
        Init();
        cin >> s >> t >> k;
        while (k--) {
            cin >> u >> v >> c;
            if (!cap[u][v]) {
                G[u].push_back(v);
                G[v].push_back(u);
            }
            cap[v][u] = (cap[u][v] += c);
        }
        

        cout << "Network " << ++kase << '\n';
        cout << "The bandwidth is " << MaxFlow(s, t) << ".\n\n";
    }
    return 0;
}
