#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 1005
#define MAXC 105
using namespace std;

struct Edge
{
    int from;
    int to;
    int dist;

    Edge(int u, int v, int d) : from(u), to(v), dist(d) {};
};

struct Node
{
    int p;
    vector<Edge> edges;
};

Node city[MAXN];
int d[MAXC][MAXN][MAXN];
int n;
int c;

int main()
{
    int m, q;
    memset(dist, -1, sizeof(dist));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &city[i].p);
    }
    for (int i = 0, u, v, d; i < m; i++) {
        scanf("%d%d%d", &u, &v, &d);
        city[u].edges.push_back(Edge(u,v,d));
        city[v].edges.push_back(Edge(v,u,d));
    }
    scanf("%d", &q);

    for (int c, s, e; q > 0; q--) {
        scanf("%d%d%d", &c, &s, &e);
        solve();
        print();
    }
    return 0;
}
