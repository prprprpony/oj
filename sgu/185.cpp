#include <cstdio>
#include <queue>
#include <cstdint>
#include <algorithm>
using namespace std;
const int maxn = 402;
int n;
const int inf = 1e9;
//for spfa
int g[maxn][maxn];
int d[maxn];
bool inq[maxn];
// for dinic
int s, t;
struct edge
{
	unsigned int v:9;
	unsigned int c:2;
   	int f:3;
	unsigned int rev:9;
	edge() {}
	edge(int _v, int _c, int _f, int r) : v(_v), c(_c), f(_f), rev(r) {}
};
deque<edge> e[maxn];
int lv[maxn];
int cur[maxn];

inline void spfa()
{
	fill_n(d+2,n-1,inf);
	queue<int16_t> q;
	d[1] = 0;
	inq[1] = true;
	q.push(1);
	while (q.size()) {
		int x = q.front();
		q.pop();
		inq[x] = false;
		for (int i = 1; i <= n;	++i) 
			if (g[x][i] && d[x] + g[x][i] < d[i]) {
				d[i] = d[x] + g[x][i];
				if (!inq[i]) {
					q.push(i);
					inq[i] = true;
				}
			}
	}
}
inline void add_edge(int u, int v, int c)
{
	e[u].emplace_back(v, c, 0, e[v].size());
	e[v].emplace_back(u, 0, 0, e[u].size() - 1);
}
inline bool build_level_graph()
{
	queue<int16_t> q;
	fill_n(lv, n+1, 0);
	lv[s] = 1;
	q.push(s);
	while (q.size() && !lv[t]) {
		int i = q.front();
		q.pop();
		for (const auto & x : e[i])
			if (!lv[x.v] && x.c - x.f > 0) {
				lv[x.v] = lv[i] + 1;
				q.push(x.v);
			}
	}
	return lv[t];
}
int augment(int u, int a)
{
	if (u == t)
		return a;
	if (lv[u] == lv[t])
		return 0;
	int flow = 0;
	for (int & i = cur[u]; i < e[u].size(); ++i) {
		auto & x = e[u][i];
		if (lv[x.v] == lv[u] + 1 && x.c - x.f > 0) {
			int aug = augment(x.v, min(a, x.c - x.f));
			a -= aug;
			flow += aug;
			x.f += aug;
			e[x.v][x.rev].f -= aug;
			if (!a)
				break;
		}
	}
	return flow;
}
inline int dinic()
{
	int mf = 0;
	while (build_level_graph()) {
		fill_n(cur, n+1, 0);
		mf += augment(s, inf);
	}
	return mf;
}
int main()
{
	int m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int x, y, l;
		scanf("%d%d%d", &x, &y, &l);
		g[x][y] = g[y][x] = l;
	}
	spfa();

	s = 0, t = n;
	add_edge(0, 1, 2);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (g[i][j] && d[i] + g[i][j] == d[j])
				add_edge(i, j, 1);
	if (dinic() == 2) {
		for (int i = 0; i < 2; ++i) {
			int u = 1;
			while (u != n) {
				printf("%d ", u);
				for (auto & y : e[u])
					if (y.f == 1) {
						u = y.v;
						y.f = 0;
						break;
					}
			}
			printf("%d\n", n);
		}
	} else {
		puts("No solution");
	}
}
