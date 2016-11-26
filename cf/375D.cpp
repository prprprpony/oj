#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int maxn = 1.12e5, BS = 318;
int n, m;
int c[maxn];
vector<int> g[maxn];
int tp;
int et[maxn];
pii rg[maxn];
struct qry
{
	int i, b, l, r, k;
	qry() {}
	qry(int j, int u, int v) : i(j), b(rg[u].F / BS), l(rg[u].F), r(rg[u].S), k(v) {}
	bool operator < (const qry & a) const
	{
		return b < a.b || (b == a.b && r < a.r);
	}
} q[maxn];
int ans[maxn];
int cnt[maxn];
int BIT[maxn];
void dfs(int p, int u)
{
	rg[u].F = tp;
	et[tp++] = c[u];
	for (int v : g[u])
		if (v != p) 
			dfs(u, v);
	rg[u].S = tp;
}
void add(int i, int v)
{
	if (i <= 0)
		return;
	for ( ; i <= n; i += i & -i)
		BIT[i] += v;
}
int sum(int i)
{
	int ret = 0;
	for ( ; i; i ^= i & -i)
		ret += BIT[i];
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	tp = 0;
	dfs(0,1);
	int qn = 0;
	for (int i = 0; i < m; ++i) {
		int u, k;
		cin >> u >> k;
		if (k > rg[u].S - rg[u].F)
			continue;
		q[qn++] = qry(i,u,k);
	}
	sort(q, q + qn);
	int l,r;
	l = r = q[0].l;
	for (int i = 0; i < qn; ++i) {
		while (r < q[i].r) {
			add(cnt[et[r]], -1);
			add(++cnt[et[r]], 1);
			++r;
		}
		while (l > q[i].l) {
			--l;
			add(cnt[et[l]], -1);
			add(++cnt[et[l]], 1);
		}
		while (r > q[i].r) {
			--r;
			add(cnt[et[r]], -1);
			add(--cnt[et[r]], 1);
		}
		while (l < q[i].l) {
			add(cnt[et[l]], -1);
			add(--cnt[et[l]], 1);
			++l;
		}
		ans[q[i].i] = sum(n) - sum(q[i].k - 1);
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << '\n';
}
