/* -std=c99 */
#include <stdio.h>
typedef long long ll;
#define N 42
#define INF ((ll)1e18)
ll min(ll x, ll y) {return x < y ? x : y;}
ll a[N][N], row[N][N], col[N][N], dp[N][N][N][N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%lld",a[i]+j);
			row[i][j] = col[i][j] = a[i][j];
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			row[i][j] += row[i][j-1];
			col[i][j] += col[i-1][j];
		}
	for (int w = 1; w <= n; ++w)
		for (int h = 1; h <= m; ++h)
			for (int x0 = 1, x1; (x1 = x0 + w - 1) <= n; ++x0)
				for (int y0 = 1, y1; (y1 = y0 + h - 1) <= m; ++y0) {
					ll * d = &dp[x0][x1][y0][y1];
					*d = INF;
					for (int i = x0; i <= x1; ++i)
						for (int j = y0; j <= y1; ++j)
							*d = min(*d, (row[i][y1] - row[i][y0-1] + col[x1][j] - col[x0-1][j] - a[i][j]) * a[i][j]
									+ dp[x0][i-1][y0][j-1]
									+ dp[i+1][x1][y0][j-1]
									+ dp[x0][i-1][j+1][y1]
									+ dp[i+1][x1][j+1][y1]
							);
				}
	printf("%lld\n", dp[1][n][1][m]);
}
