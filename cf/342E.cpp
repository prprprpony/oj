#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,s,e) for (auto i = (s), __e = (e); i != __e; ++i)
#define rp(i, e) rep(i, 0, e)
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()
#define F first
#define S second
// read integers
int RI() {return 0;}
template<typename T>
int RI(T & a)
{
	int c;
	int s = 1;
	while (!((c = getchar()) == '-' || isdigit(c) || c == EOF));
	if (c == EOF)
		return 0;
	if (c == '-') {
		s = -1;
		c = getchar();
	}
	a = 0;
	do {
		a = 10 * a + s * (c - '0');
	} while (isdigit(c = getchar()));
	return 1;
}
template<typename T, typename... Args>
int RI(T & a, Args & ... args) {return RI(a) ? 1 + RI(args...) : 0;}
//print integers, python style
template<typename T>
void __PI(T a)
{
	static const int maxd = 25;
	static char d[maxd];
	int i = maxd - 1;
	int s = a < 0 ? -1 : 1;
	do {
		d[--i] = s * (a % 10) + '0';
	} while (a /= 10);
	if (s < 0)
		d[--i] = '-';
	fputs(d + i, stdout);
}
template<char sep>
void __PSI() {}
template<char sep, typename T>
void __PSI(const T & a) {putchar(sep), __PI(a);}
template<char sep, typename T, typename... Args>
void __PSI(const T & a, const Args & ... args) {__PSI<sep, T>(a), __PSI<sep, Args...>(args...);}
template<char sep = ' ', char end = '\n', typename T, typename... Args>
void PI(const T & a, const Args & ... args) {__PI(a), __PSI<sep, Args...>(args...), putchar(end);}

const int maxn = 1.12e5, inf = 8e7;
typedef pair<int,int> pii;
vector<int> g[maxn];
// eular tour technique && sparse table
const int ettn = maxn * 2;
int top;
int et[ettn]; 
pii rg[maxn];  // [F, S)
const int maxk = __lg(ettn) + 1;
int st[maxk][ettn];
void ett(int p, int u, int d)
{
	rg[u].F = top;
	et[top++] = d;
	for (auto v : g[u]) if (v != p) {
		ett(u, v, d + 1);
		et[top++] = d;
	}
	rg[u].S = top;
}
void build_ett()
{
	top = 0;
	ett(0, 1, 0);
	int n = top;
	copy(et, et + n, st[0]);
	for (int k = 1; (1 << k) < n; ++k)
		rp(i,n - (1 << k))
			st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}
int dist(int a, int b)
{
	int l = min(rg[a].F, rg[b].F);
	int r = max(rg[a].S, rg[b].S);
	int k = __lg(r - l);
	int u = min(st[k][l], st[k][r - (1 << k)]);
	return et[rg[a].F] + et[rg[b].F] - 2 * u;
}
// centroid tree
int cent, ctmc;
int sz[maxn];
int pa[maxn]; 
int ans[maxn];
void getsz(int p, int u)
{
	sz[u] = 1;
	for (auto v : g[u]) if (v != p) {
		getsz(u, v);
		sz[u] += sz[v];
	}
}
void dfs(int p, int u, int n)
{
	int mc = 0;
	for (auto v : g[u]) if (v != p) {
		dfs(u, v, n);
		mc = max(mc, sz[v]);
	}
	mc = max(mc, n - sz[u]);
	if (mc < ctmc) {
		cent = u;
		ctmc = mc;
	}
}
int find_centroid(int u, int n)
{
	cent = 0;
	ctmc = n + 87;
	dfs(0, u, n);
	return cent;
}
void build(int p, int u) 
{
	u = find_centroid(u, sz[u]);
	pa[u] = p;
	for (auto v : g[u]) {
		for (auto & x : g[v]) if (x == u) {
			x = g[v].back();
			g[v].pop_back();
			break;
		}
		if (sz[v] > sz[u])
			getsz(u, v);
		build(u, v);
	}
}
void build_ct()
{
	getsz(0, 1);
	build(0, 1);
}
void chg(int v)
{
	for (int u = v; u; u = pa[u]) 
		ans[u] = min(ans[u], dist(u, v));
}
int qry(int v)
{
	int ret = inf;
	for (int u = v; u; u = pa[u]) 
		ret = min(ret, ans[u] + dist(u, v));
	return ret;
}
int main()
{
	int n, m;
	RI(n, m);
	rp(i,n-1) {
		int a, b;
		RI(a, b);
		g[a].pb(b);
		g[b].pb(a);
	}
	build_ett();
	build_ct();
	fill_n(ans+1, n, inf);
	chg(1);
	while (m--) {
		int t, v;
		RI(t, v);
		if (t == 1)
			chg(v);
		else
			PI(qry(v));
	}
}
