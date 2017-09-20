#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 987;
vector<int> g[N];
int c[2];
void dfs(int p,int u,int i)
{
	++c[i];
	for (int v : g[u]) if (v != p)
		dfs(u,v,i^1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,1,0);
	cout << c[0] * 1LL * c[1] - (n - 1) << '\n';
}
