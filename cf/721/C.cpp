#include <bits/stdc++.h>
#define D first
#define F second
using namespace std;
const int maxn = 5001;
typedef pair<int,short> pii;
int n, m, T;
vector<pii> g[maxn];
int d[maxn][maxn];
bool vis[maxn];
short pre[maxn][maxn];
void dp(int i)
{
	if (vis[i])
		return;
	vis[i] = true;
	for (int j = 1; j <= n; ++j)
		d[i][j] = T + 1;
	for (auto p : g[i])
		if (p.F == 1) {
			d[i][2] = p.D;
			pre[i][2] = 1;
		} else {
			dp(p.F);
			for (int j = 3; j <= n; ++j) {
				int v = d[p.F][j-1] + p.D;
				if (d[i][j] > v) {
					d[i][j] = v;
					pre[i][j] = p.F;
				}
			}
		}
}
void print(int i, int j)
{
	if (i != 1)
		print(pre[i][j], j-1);
	printf("%d%c", i, i == n ? '\n' : ' ');
}
int main()
{
	scanf("%d%d%d", &n, &m, &T);
	for (int i = 0; i < m; ++i) {
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		g[v].emplace_back(t, u);
	}
	vis[1] = true;
	d[1][1] = 0;
	for (int i = 2; i <= n; ++i)
		d[1][i] = T + 1;
	dp(n);
	int ans;
	for (ans = n; d[n][ans] > T; --ans);
	printf("%d\n", ans);
	print(n, ans);
}
