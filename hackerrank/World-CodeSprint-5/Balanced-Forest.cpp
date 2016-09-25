#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int i;
	ll sum;
	int l;
	int r;
	node(int j, ll s, int k, int q) : i(j), sum(s), l(k), r(q) {}
	bool operator < (const node & x) const
	{
		return sum < x.sum || (sum == x.sum && l < x.l);
	}
};
const int maxn = 5.4e4;
int c[maxn];
vector<int> g[maxn];
vector<node> a;
int cnt;
void dfs(int p, int u)
{
	int l = ++cnt;
	ll s = c[u];
	for (auto x : g[u]) if (x != p) {
		dfs(u, x);
		++cnt;
		s += a.back().sum;
	}
	a.emplace_back(u, s, l, cnt);
}
void solve()
{
	int n;
	ll s = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		cin >> c[i];
		s += c[i];
	}
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	a.clear();
	cnt = 0;
	dfs(0,1);
	sort(a.begin(), a.end());
	ll ans = s;
	int p = lower_bound(a.begin(), a.end(), node(0, (s + 2) / 3, 0, 0)) - a.begin();
	for (int i = p; i < a.size() && a[i].sum <= s / 2; ++i) {
		bool ok = false;
		ll w = a[i].sum;
		ll v = s - 2 * w;
		if (i + 1 < a.size() && a[i+1].sum == w)
			ok = true;
		if (!ok) {
			int j = lower_bound(a.begin(), a.end(), node(0, v, a[i].l, 0)) - a.begin() - 1;
			if (0 <= j && a[j].sum == v)
				ok = true;
		}
		if (!ok) {
			int j = upper_bound(a.begin(), a.end(), node(0, v, a[i].r, 0)) - a.begin();
			if (j < n && a[j].sum == v)
				ok = true;
		}
		if (!ok) {
			int j = upper_bound(a.begin(), a.end(), node(0, w + v, a[i].l, 0)) - a.begin() - 1;
			if (j >= 0 && a[j].sum == w + v && a[j].r > a[i].r)
				ok = true;
		}
		if (!ok) {
			int j = upper_bound(a.begin(), a.end(), node(0, w + w, a[i].l, 0)) - a.begin() - 1;
			if (j >= 0 && a[j].sum == w + w && a[j].r > a[i].r)
				ok = true;
		}
		if (ok) {
			ans = w - v;
			break;
		}
	}
	for (int i = p - 1; i >= 0; --i) {
		ll v = a[i].sum;
		ll w = s - v;
		if (w & 1)
			continue;
		w >>= 1;
		if (w - v >= ans)
			break;
		int j = upper_bound(a.begin(), a.end(), node(0, w + v, a[i].l, 0)) - a.begin() - 1;
		if (j >= 0 && a[j].sum == w + v && a[j].r > a[i].r) {
			ans = w - v;
			break;
		}
	}
	cout << (ans != s ? ans : -1) << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while (q--)
		solve();
}
