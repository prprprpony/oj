#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> 
using namespace std;
const int inf = 2e9;
const int maxn = 1.12e4;
struct edge
{
	int u, v, w;
	edge() {}
	edge(int a, int b, int c) : u(a), v(b), w(c) {}
};
struct node // seg tree
{
	node * lc, * rc;
	int tg, mx, mn;
	node() {}
	node(int v) : lc(NULL), rc(NULL), tg(0), mx(v), mn(v) {}
};
vector<int> g[maxn];
edge e[maxn];
int pa[maxn];
int dep[maxn];
int sz[maxn];
int hvptr;
int hvhd[maxn];
node * hvrt[maxn];
int hvsz[maxn];
int hc[maxn]; // heaviest child
int hn[maxn]; // heavy chain number
int hi[maxn]; // index on heavy chain 
int wt[maxn];
int arr[maxn];
node tr[maxn << 2];
node * ptr;
void dfs(int d, int p, int u)
{
	pa[u] = p;
	dep[u] = d;
	sz[u] = 1;
	hc[u] = 0;
	for (int i = 0; i < g[u].size();++i) {
		int v = g[u][i];
		if (v != p) {
			dfs(d+1, u, v);
			sz[u] += sz[v];
			if (sz[v] > sz[hc[u]])
				hc[u] = v;
		}
	}
}
inline void neg(node * o)
{
	o->tg ^= 1;
	o->mx *= -1;
	o->mn *= -1;
	swap(o->mx, o->mn);
}
inline void push(node * o)
{
	if (o->tg) {
		o->tg = 0;
		neg(o->lc);
		neg(o->rc);
	}
}
inline void pull(node * o)
{
	o->mx = max(o->lc->mx, o->rc->mx);
	o->mn = min(o->lc->mn, o->rc->mn);
}
node * build_seg_tree(int l, int r)
{
	node * o = ptr++;
	if (r - l == 1) {
		*o = node(arr[l]);
	} else {
		int m = l + ((r-l)>>1);
		o->lc = build_seg_tree(l, m);
		o->rc = build_seg_tree(m, r);
		o->tg = 0;
		pull(o);
	}
	return o;
}
void chg(node * o, int l, int r, int i, int v)
{
	if (r - l == 1) {
		*o = node(v);
	} else {
		push(o);
		int m = l + ((r-l)>>1);
		if (i < m)
			chg(o->lc, l, m, i, v);
		else
			chg(o->rc, m, r, i, v);
		pull(o);
	}
}
void neg(node * o, int l, int r, int i, int j)
{
	if (r <= i || j <= l)
		return;
	if (i <= l && r <= j) {
		neg(o);
	} else {
		push(o);
		int m = l + ((r-l)>>1);
		neg(o->lc, l, m, i, j);
		neg(o->rc, m, r, i, j);
		pull(o);
	}
}
int qry(node * o, int l, int r, int i, int j)
{
	if (r <= i || j <= l)
		return -inf;
	if (i <= l && r <= j) {
		return o->mx;
	} else {
		push(o);
		int m = l + ((r-l)>>1);
		return max(qry(o->lc, l, m, i, j), qry(o->rc, m, r, i, j));
	}
}

void build(int u)
{
	if (!hn[u]) {
		int j = 1;
		arr[0] = wt[u];
		for (int i = hc[u]; i; i = hc[i], ++j)
			arr[j] = wt[i];
		hn[u] = hvptr++;
		hvhd[hn[u]] = u;
		hvrt[hn[u]] = build_seg_tree(0,j);
		hvsz[hn[u]] = j;
		hi[u] = 0;
		j = 1;
		for (int i = hc[u]; i; i = hc[i], ++j) {
			hn[i] = hn[u];
			hi[i] = j;
		}
	}
	for (int i = 0; i < g[u].size();++i) {
		int v = g[u][i];
		if (v != pa[u])
			build(v);
	}
}
inline void solve()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		g[i].clear();
	for (int i = 1; i < N; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(b);
		g[b].push_back(a);
		e[i] = edge(a, b, c);
	}
	dfs(0,0,1);
	for (int i = 1; i < N ;++i) {
		if (dep[e[i].u] > dep[e[i].v])
			swap(e[i].u, e[i].v);
		wt[e[i].v] = e[i].w;
	}
	ptr = tr;
	hvptr = 1;
	memset(hn+1, 0, N * sizeof(int));
	build(1);
	char cmd[8];
	while (scanf("%s", cmd) == 1 && cmd[0] != 'D') {
		if (cmd[0] == 'C') {
			int i, v;
			scanf("%d%d", &i, &v);
			i = e[i].v;
			chg(hvrt[hn[i]], 0, hvsz[hn[i]], hi[i], v);
		} else if (cmd[0] == 'N') {
			int a, b;
			scanf("%d%d", &a, &b);
			while (hn[a] != hn[b]) {
				if (dep[hvhd[hn[a]]] < dep[hvhd[hn[b]]])
					swap(a, b);
				neg(hvrt[hn[a]], 0, hvsz[hn[a]], 0, hi[a]+1);
				a = pa[hvhd[hn[a]]];
			}
			if (hi[a] > hi[b])
				swap(a, b);
			if (hi[a] + 1 <= hi[b])
				neg(hvrt[hn[a]], 0, hvsz[hn[a]], hi[a]+1, hi[b]+1);
		} else { // "QUERY"
			int a, b;
			scanf("%d%d", &a, &b);
			int ans = -inf;
			while (hn[a] != hn[b]) {
				if (dep[hvhd[hn[a]]] < dep[hvhd[hn[b]]])
					swap(a, b);
				ans = max(ans, qry(hvrt[hn[a]], 0, hvsz[hn[a]], 0, hi[a]+1));
				a = pa[hvhd[hn[a]]];
			}
			if (hi[a] > hi[b])
				swap(a, b);
			if (hi[a] + 1 <= hi[b])
				ans = max(ans, qry(hvrt[hn[a]], 0, hvsz[hn[a]], hi[a]+1, hi[b]+1));
			 printf("%d\n", ans);
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
