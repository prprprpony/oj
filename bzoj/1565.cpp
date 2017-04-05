#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i(a),_E(b);i<_E;++i)
#define RP(i,n) REP(i,0,n)
#define PB push_back
#define SZ(a) ((int)(a.size()))
#define ALL(a) a.begin(), a.end()
typedef vector<int> vi;
template<typename T> inline T cmin(T & a, T b) {return a = min(a,b);}
template<typename T> inline T cmax(T & a, T b) {return a = max(a,b);}

/* DUCK HORSE */
struct Dinic {
	const static int maxn = 870;
	const static int inf = 2147483647;
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

	void Init(int num,int a,int b)
	{
		n = num;
		s = a;
		t = b;
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
}  flower;

const int N = 666;
int n,m;
int w[N];
vi g[N];
int dfn,low[N],st[N],tp,ons[N],ok[N];
inline int id(int r, int c) {return r * m + c;}
void dfs(int u)
{
    int tsp = low[u] = ++dfn;
    st[tp++] = u;
	ok[u] = ons[u] = 1;
	RP(i,SZ(g[u])) {
		int v = g[u][i];
		if (!low[v])
			dfs(v);
		if (ons[v])
			cmin(low[u], low[v]);
		ok[u] = ok[u] && ok[v];
	}
	if (low[u] == tsp) {
		int v;
		do {
			v = st[--tp];
			ons[v] = 0;
		} while (v!=u);
	} else {
		ok[u] = 0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	RP(i,n)
		RP(j,m) {
			int v = id(i,j), k;
			if (j<m-1)
				g[v].PB(id(i,j+1));
			scanf("%d%d",w+v, &k);
			while (k--) {
				int r,c;
				scanf("%d%d",&r,&c);
				g[id(r,c)].PB(v);
			}
		}
	RP(i,n*m) if (!low[i]) dfs(i);
	int fn = n * m + 2;
	flower.Init(fn,fn-2,fn-1);
	int ans = 0;
	RP(i,n*m) if (ok[i]) {
		if (w[i] > 0) {
			flower.AddEdge(flower.s,i,w[i]);
			ans += w[i];
		} else if (w[i] < 0)
			flower.AddEdge(i,flower.t,-w[i]);
		RP(j,SZ(g[i])) {
			int v = g[i][j];
			if (!ok[v]) continue;
			flower.AddEdge(i,v,flower.inf);
		}
	}
	printf("%d\n",ans-flower.MaxFlow());
}
