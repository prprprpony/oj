#include <bits/stdc++.h>
using namespace std;

const int maxn = 514;
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
int d[maxn]; // for BFS
queue<int> lg[maxn]; // level graph, adjacent list of edge index
int n, s, t;

void Init(int num)
{
    n = num;
    edges.clear();
    for (int i = 0; i < n; i++)
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
    memset(d, -1, n * sizeof(int));
    d[s] = 0;
    queue<int> q;
    q.push(s);
    int x;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        lg[x] = queue<int>(); // clear lg[x]
        if (d[t] != -1 && d[x] >= d[t]) // 
            break;
        for (int i = 0; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (e.cap > e.flow) {
                if (d[e.to] == -1) {
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
                if (d[e.to] == d[x] + 1)
                    lg[x].push(g[x][i]);
            }
        }
    }
    return d[t] != -1;
}

int DFS(int x, int a)
{
    if (x == t)
        return a;
    if (lg[x].empty() || d[x] >= d[t] || a == 0)
        return 0;

    int flow = 0, f, i;
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

int T,R,C;
int id(int r,int c) {return r * C + c;}

int main()
{
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		scanf("%d%d", &R, &C);
		int num = R*C+R+C+2, m = R*C;
		s = num-2, t = num-1;
		Init(num);
		int la = 0;
		for (int i = 0; i < R; ++i) {
			int v;
			scanf("%d",&v);
			for (int j = 0; j < C; ++j)
				AddEdge(m+i,id(i,j),19);
			AddEdge(s,m+i,v-la-C);
			la = v;
		}
		m += R;
		la = 0;
		for (int i = 0; i < C; ++i) {
			int v;
			scanf("%d",&v);
			for (int j = 0; j < R; ++j)
				AddEdge(id(j,i),m+i,19);
			AddEdge(m+i,t,v-la-R);
			la = v;
		}
		m -= R;
		MaxFlow();
		printf("Matrix %d\n", kase);
		for (int r = 0; r < R; ++r)
			for (int c = 0; c < C; ++c)
				printf("%d%c", edges[g[m+r][c]].flow+1, " \n"[c==C-1]);
		puts("");
	}
}
