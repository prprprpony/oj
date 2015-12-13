#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 105;
const int inf = 1000000007;
struct Edge
{
    int from;
    int to;
    int cap;
    int flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
vector<Edge> edges;
vector<int> g[maxn];
int s, t;
int d[maxn];
int cur[maxn];
int nv;
void Init(int n) {
    edges.clear();
    for (int i = 0; i < n; i++)
        g[i].clear();
    nv = n;
}
void AddeEdge(int from, int to, int cap)
{
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    g[from].push_back(edges.size() - 2);
    g[to].push_back(edges.size() - 1);
}
bool ConstructLevelGraph()
{
    memset(d, 0, nv * sizeof(int));
    d[s] = 1;
    queue<int> q;
    int x;
    q.push(s);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (d[t] && d[x] + 1 > d[t])
            break;
        for (int i = 0; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (!d[e.to] && e.cap > e.flow) {
                d[e.to] = d[x] + 1;
                q.push(e.to);
            }
        }
    }
    return d[t] != 0;
}
int AugmentBlockingFlow(int x, int a)
{
    if (x == t || a == 0)
        return a;
    int flow = 0, f;
    for (int &i = cur[x]; i < g[x].size(); i++) {
        Edge &e = edges[g[x][i]];
        if (d[e.to] == d[x] + 1 && (f = AugmentBlockingFlow(e.to, min(a, e.cap - e.flow))) > 0) {
            e.flow += f;
            edges[g[x][i] ^ 1].flow -= f;
            flow += f;
            a -= f;
            if (a == 0)
                break;
        }
    }
    return flow;
}
int MaxFlow()
{
    int flow = 0;
    while (ConstructLevelGraph()) {
        memset(cur, 0, nv * sizeof(int));
        flow += AugmentBlockingFlow(s, inf);
    }
    return flow;
}
int main()
{
    int n, p, c, m;
    int u, v, cap;
    while (scanf("%d%d%d%d ", &n, &p ,&c, &m) == 4) {
        s = n;
        t = n + 1;
        Init(n + 2);
        while (m--) {
            scanf("(%d,%d)%d ", &u, &v, &cap);
            if (u != v)
                AddeEdge(u, v, cap);
        }
        while (p--) {
            scanf("(%d)%d ", &u, &cap);
            AddeEdge(s, u, cap);
        }
        while (c--) {
            scanf("(%d)%d ", &u, &cap);
            AddeEdge(u, t, cap);
        }
        printf("%d\n", MaxFlow());
    }
    return 0;
}
