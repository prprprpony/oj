#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 105;
const long long inf = 1000000000000000000;
int n;
int s, t;
struct Edge
{
    int from;
    int to;
    long long cap;
    long long flow;
    long long cost;
    Edge(int u, int v, long long c, long long f, long long k) : from(u), to(v), cap(c), flow(f), cost(k) {}
};
vector<Edge> edges;
vector<int> g[maxn];
long long d[maxn];
long long a[maxn];
int p[maxn];
bool inq[maxn];
void Init()
{
    edges.clear();
    for (int i = 1; i <= n; i++)
        g[i].clear();
}
void AddEdge(int u, int v, long long cap, long long cost)
{
    edges.push_back(Edge(u, v, cap, 0, cost));
    edges.push_back(Edge(v, u, 0, 0, -cost));
    g[u].push_back(edges.size() - 2);
    g[v].push_back(edges.size() - 1);
}
bool BellmanFord()
{
    for (int i = 1; i <= n; i++)
        d[i] = inf;
    queue<int> q;
    q.push(s);
    memset(inq + 1, 0, n * sizeof(bool));
    d[s] = 0;
    a[s] = inf;
    int x;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        inq[x] = false;
        for (int i = 0; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (e.cap > e.flow && d[e.to] > d[x] + e.cost) {
                d[e.to] = d[x] + e.cost;
                a[e.to] = min(a[x], e.cap - e.flow);
                p[e.to] = g[x][i];
                if (!inq[e.to]) {
                    q.push(e.to);
                    inq[e.to] = true;
                }
            }
        }
    }
    return d[t] != inf;
}
long long MinCostFlow(long long mf) {
    long long cost = 0;
    while (BellmanFord() && mf) {
        if (a[t] > mf)
            a[t] = mf;
        cost += a[t] * d[t];
        mf -= a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
    }
    if (mf)
        return -1;
    return cost;
}
int main()
{
    int m, u, v;
    long long maxflow, mincost, cost, k;
    while (cin >> n >> m) {
        Init();
        s = 1;
        t = n;
        while (m--) {
            cin >> u >> v >> cost;
            AddEdge(u, v, 1, cost);
            AddEdge(v, u, 1, cost);
        }
        cin >> maxflow >> k;
        for (int i = 0; i < edges.size(); i += 2)
            edges[i].cap = k;
        mincost = MinCostFlow(maxflow);
        if (mincost != -1)
            cout << mincost;
        else
            cout << "Impossible.";
        cout << '\n';
    }
    return 0;
}
