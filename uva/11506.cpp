#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 110;
const int inf = 1000000000;
struct Edge
{
    int from;
    int to;
    int cap;
    int flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
vector<Edge> edges;
vector<int> G[maxn];
int a[maxn];
int p[maxn];
void Init()
{
    edges.clear();
    for (int i = 0; i < maxn; i++)
        G[i].clear();
}
void AddEdge(int from, int to, int cap)
{
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    G[from].push_back(edges.size() - 2);
    G[to].push_back(edges.size() - 1);
}
// Edmonds-Karp
int MaxFlow(int s, int t)
{
    int flow = 0;
    while (1) {
        memset(a, 0, sizeof(a));
        queue<int> q;
        q.push(s);
        a[s] = inf;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (vector<int>::iterator it = G[x].begin(); it != G[x].end(); it++) {
                Edge &e = edges[*it];
                if (!a[e.to] && e.cap > e.flow) {
                    a[e.to] = min(a[x], e.cap - e.flow);
                    p[e.to] = *it;
                    q.push(e.to);
                }
            }
            if (a[t])
                break;
        }
        if (!a[t])
            break;
        flow += a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
    }
    return flow;
}
int main()
{
    int m, w;
    while (cin >> m >> w && m) {
        Init();
        for (int i = 0, u, c; i < m - 2; i++) {
            cin >> u >> c;
            AddEdge(u, u + m, c);
        }
        for (int i = 0, u, v, c; i < w; i++) {
            cin >> u >> v >> c;
            if (u > v)
                swap(u, v);
            if (u != 1 && v != m) {
                AddEdge(u + m, v, c);
                AddEdge(v + m, u, c);
            } else if (u == 1 && v != m) {
                AddEdge(1, v, c);
            } else if (u != 1 && v == m) {
                AddEdge(u + m, m, c);
            } else {
                AddEdge(1, m, c);
            }
        }
        cout << MaxFlow(1, m) << '\n';
    }
    return 0;
}
