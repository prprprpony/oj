#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 205;
const int inf = 2147483647;

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
int d[maxn];
queue<int> lg[maxn];
int n, m, s, t;

void Init()
{
    edges.clear();
    for (int i = 1; i <= n; i++)
        g[i].clear();
}

void AddEdge(int from, int to, int cap)
{
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    g[from].push_back(edges.size() - 2);
    g[to].push_back(edges.size() - 1);
}

bool BFS()
{
    memset(d, 0, (n + 1) * sizeof(int));
    d[s] = 1;
    queue<int> q;
    q.push(s);
    int x;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        lg[x] = queue<int>();
        if (d[t] && d[x] >= d[t])
            break;
        for (int i = 0; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (e.cap > e.flow) {
                if (!d[e.to]) {
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
                if (d[e.to] == d[x] + 1)
                    lg[x].push(g[x][i]);
            }
        }
    }
    return d[t] != 0;
}

int DFS(int x, int a)
{
    if (x == t)
        return a;
    if (lg[x].empty() || d[x] >= d[t] || a == 0)
        return 0;
    int flow = 0, f;
    int i;
    do {
        i = lg[x].front();
        Edge &e = edges[i];
        if ((f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
            e.flow += f;
            edges[i ^ 1].flow -= f;
            flow += f;
            a -= f;
            if (a == 0)
                break;
        }
        lg[x].pop();
    } while(!lg[x].empty());

    return flow;
}

int MaxFlow()
{
    int flow = 0;
    while (BFS())
        flow += DFS(s, inf);
    return flow;
}

int main()
{
    int u, v, c;
    while (scanf("%d%d", &m, &n) == 2) {
        Init();
        s = 1;
        t = n;
        while (m--) {
            scanf("%d%d%d", &u, &v, &c);
            AddEdge(u, v, c);
        }
        printf("%d\n", MaxFlow());
    }

    return 0;
}
