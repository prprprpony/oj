#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.28e5;
int c[maxn];
vector<int> g[maxn];
bool vis[maxn];
unordered_map<int,int> cnt;
int mx;
int dfs(int u)
{
	vis[u] = true;
	int sz = 1;
	mx = max(mx, ++cnt[c[u]]);
	for (auto v : g[u])
		if (!vis[v])
			sz += dfs(v);
	return sz;
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", c + i);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		g[l].push_back(r);
		g[r].push_back(l);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			cnt.clear();
			mx = 0;
			int sz = dfs(i);
			ans += sz - mx;
		}
	printf("%d\n", ans);
}
