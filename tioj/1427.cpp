#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
char a[maxn], b[maxn];
int dp[2][maxn][11][2];
int main()
{
	int m, n, k;
	scanf("%d%d%d%s%s", &m, &n, &k, a + 1, b + 1);
	int i, r;
	for (r = 1, i = 1; r <= m; ++r, i ^= 1)
		for (int j = 1; j <= n; ++j)
			for (int l = 1; l <= k; ++l) {
				dp[i][j][l][0] = max(max(max(dp[i^1][j][l][1], dp[i][j-1][l][1]), max(dp[i^1][j][l][0], dp[i][j-1][l][0])), max(dp[i][j][l-1][1], dp[i][j][l-1][0]));
				if (a[r] == b[j])
					dp[i][j][l][1] = (a[r] == 'a' ? 1 : 0) + max(dp[i^1][j-1][l][1], dp[i^1][j-1][l-1][0]);
				else
					dp[i][j][l][1] = 0;
			}
	printf("%d\n", 2 * max(dp[i^1][n][k][0],dp[i^1][n][k][0]));
}
