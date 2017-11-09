#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 877;
vector<int> g[N];
bool vis[N];
int n, m;
ll ans;
void dfs(int u)
{
	vis[u] = 0;
	ans += g[u].size() * (g[u].size() - 1LL) / 2;
	for (int v : g[u]) 
		if (vis[v])
			dfs(v);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	ll cs = 0;
	int u, v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		if (u == v)
			++cs;
		else
			g[u].push_back(v), g[v].push_back(u);
		vis[u] = vis[v] = 1;
	}
	ans = cs * (m - cs) + cs * (cs - 1) / 2;
	dfs(u);
	bool ok = 1;
	for (int i = 1; i <= n; ++i)
		ok = ok && !vis[i];
	cout << (ok ? ans : 0) << '\n';
}
