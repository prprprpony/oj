#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5006, inf = 1e15;
ll dp[N][N][2], c[N], d[N], sz[N];
vector<int> g[N];
template<typename T>
T cmin(T & x, T y) {return x = min(x,y);}
void dfs(int u)
{
	sz[u] = 1;
	dp[u][1][0] = c[u];
	dp[u][1][1] = d[u];
	for (int v : g[u]) {
		dfs(v);
		for (int i = sz[u] + 1; i <= sz[u] + sz[v]; ++i)
			dp[u][i][0] = dp[u][i][1] = inf;
		for (int i = sz[u]; i >= 0; --i)
			for (int j = sz[v]; j >= 1; --j)
				cmin(dp[u][i+j][0], dp[u][i][0] + 
dp[v][j][0]);
		for (int i = sz[u]; i >= 1; --i)
			for (int j = sz[v]; j >= 1; --j)
				cmin(dp[u][i+j][1], dp[u][i][1] + 
min(dp[v][j][0], dp[v][j][1]));
		sz[u] += sz[v];
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, b;
	cin >> n >> b;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i] >> d[i];
		d[i] = c[i] - d[i];
		if (i > 1) {
			int x;
			cin >> x;
			g[x].push_back(i);
		}
	}
	dfs(1);
	int k = 0;
	while (++k <= n && b >= min(dp[1][k][0], dp[1][k][1]));
	cout << k-1 << '\n';
}
