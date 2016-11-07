#include <bits/stdc++.h>
using namespace std;
const int maxn = 1006;
const int inf = 1e9;
const int dr[] = {0, 1, -1, 0};
const int dc[] = {-1, 0, 0, 1};
int g[maxn][maxn];
int d[maxn][maxn][2];
struct pt
{
	int r, c, t;
	pt() {}
	pt(int x, int y, int z) : r(x), c(y), t(z) {}
};
inline int gett(int a, int b) {return b + 1LL - a < 0 ? 0 : 1;}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &g[i][j]);
			d[i][j][0] = d[i][j][1] = inf;
		}
	d[1][1][0] = d[1][1][1] = 1;
	queue<pt> q;
	q.push({1, 1, 0});
	q.push({1, 1, 1});
	while (q.size() && d[n][n][0] == inf && d[n][n][1] == inf) {
		pt now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int r = now.r + dr[i], c = now.c + dc[i];
			if (1 <= r && r <= n && 1 <= c && c <= n && gett(g[now.r][now.c], g[r][c]) != now.t && d[r][c][now.t^1] == inf) {
				d[r][c][now.t^1] = d[now.r][now.c][now.t] + 1;
				q.push({r, c, now.t^1});
			}
		}
	}
	if (d[n][n][0] == inf && d[n][n][1] == inf)
		puts("-1");
	else
		printf("%d\n", min(d[n][n][0], d[n][n][1]));
}
