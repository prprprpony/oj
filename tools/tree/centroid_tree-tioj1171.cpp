#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

/*** centroid_tree.cpp ***/
// tree: stored in g[], 1-indexed
// euler tour technique + sparse table: O(n log n) preprocess, O(1) query dist(u, v)
// centroid tree: O(n) build, O(log n) query
const int maxn = 1.12e5;
const int etn = 2 * maxn;
const int etd = __lg(etn) + 1;
vector<pii> g[maxn];
pii st[etd][etn];
ll wt[etn];
pii rg[maxn];
int top;
void dfs(int d, int p, int u, int w)
{
	rg[u].F = top;
	st[0][top] = {d, u};
	wt[top++] = w;
	for (auto v : g[u]) if (v.F != p) {
		dfs(d + 1, u, v.F, v.S);
		st[0][top] = {d, u};
		wt[top++] = -v.S;
	}
	rg[u].S = top;
}
void build_ett()
{
	top = 0;
	dfs(0, 0, 1, 0);
	for (int i = 1; i < top; ++i)
		wt[i] += wt[i-1];
	for (int k = 1; (1 << k) <= top; ++k)
		for (int i = 0; i + (1 << k) <= top; ++i)
			st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}
ll dist(int a, int b)
{
	int l = min(rg[a].F, rg[b].F);
	int r = max(rg[a].S, rg[b].S);
	int k = __lg(r - l);
	int u = min(st[k][l], st[k][r - (1 << k)]).S;
	return wt[rg[a].F] + wt[rg[b].F] - 2 * wt[rg[u].F];
}

int sz[maxn], pa[maxn], cnt[maxn]; // pa[u] = parent of u on centroid tree
bool flag[maxn];
ll sum[maxn], stp[maxn];
pii cent;
void getsz(int p, int u)
{
	sz[u] = 1;
	for (auto v : g[u]) if (v.F != p) {
		getsz(u, v.F);
		sz[u] += sz[v.F];
	}
}
void find_ct(int p, int u, int n)
{
	int mc = 0;
	for (auto v : g[u]) if (v.F != p) {
		find_ct(u, v.F, n);
		mc = max(mc, sz[v.F]);
	}
	mc = max(mc, n - sz[u]);
	cent = min(cent, pii(mc, u));
}
int find_ct(int u, int n)
{
	cent = {n + 2333, -1};
	find_ct(-1, u, n);
	return cent.S;
}
void build(int p, int u)
{
	u = find_ct(u, sz[u]);
	pa[u] = p;
	for (auto v : g[u]) {
		for (auto & t : g[v.F])
			if (t.F == u) {
				t = g[v.F].back();
				g[v.F].pop_back();
				break;
			}
		if (sz[v.F] > sz[u])
			getsz(u, v.F);
		build(u, v.F);
	}
}
void build_ct()
{
	getsz(0, 1);
	build(0, 1);
}
void chg(int u) // change the color of node u from white to black
{
	if (flag[u])
		return;
	flag[u] = true;
	++cnt[u];
	for (int c = u, v = pa[u]; v > 0; c = v, v = pa[v]) {
		ll dvu = dist(v, u);
		sum[v] += dvu;
		stp[c] += dvu;
		++cnt[v];
	}
}
ll qry(int u) // sum of dist(u, v) for all black vertex v
{
	ll ret = sum[u];
	for (int c = u, v = pa[u]; v > 0; c = v, v = pa[v])
		ret += sum[v] - stp[c] + (cnt[v] - cnt[c]) * dist(u, v);
	return ret;
}
void init(int n)
{
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        flag[i] = false;
        sum[i] = stp[i] = 0;
    }
}
void add_edge(int a, int b, int w)
{
    g[a].emplace_back(b, w);
    g[b].emplace_back(a, w);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    init(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        ++a, ++b;
        add_edge(a, b, l);
    }
    build_ett();
    build_ct();
    while (q--) {
        int t, x;
        cin >> t >> x;
        ++x;
        if (t == 1)
            chg(x);
        else
            cout << qry(x) << '\n';
    }
}
/*** centroid_tree.cpp ***/
