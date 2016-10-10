#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1024;
const int M = N * (N - 1) / 2;
int n, m;
struct E
{
	int u, v;
	ll w;
	bool operator < (const E & a) const {return w < a.w;}
} e[M];
int p[N], sz[N];
ll wt[N];
ll add[M];
int cnt;
ll mst;
int calc(int u, int v, ll w)
{
	ll mx = 0;
	while (u != v && (p[u] != u || p[v] != v)) {
		if (sz[u] > sz[v] || p[u] == u)
			swap(u, v);
		mx = max(mx, wt[u]);
		u = p[u];
	}
	if (u == v) {
		return w - mx;
	} else {
		if (sz[u] > sz[v])
			swap(u, v);
		wt[u] = w;
		p[u] = v;
		sz[v] += sz[u];
		mst += w;
		++cnt;
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e, e + m);
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; ++i)
		add[i] = calc(e[i].u, e[i].v, e[i].w);
	if (cnt < n - 1) {
		cout << "-1 -1\n";
	} else {
		cout << mst << ' ';
		ll a = -1;
		for (int i = 0; i < m; ++i)
			if (!add[i]) {
				if (!(cnt--)) {
					a = 0;
					break;
				}
			} else {
				a = a < 0 ? add[i] : min(a, add[i]);
			}
		cout << (a < 0 ? -1 : mst + a) << '\n';
	}
}
