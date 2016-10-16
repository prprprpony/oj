#include <bits/stdc++.h>
using namespace std;
const int maxn = 16;
char a[maxn], b[maxn];
int dp[maxn][maxn];
int main()
{
	for (int i = 1; i < maxn; ++i)
		dp[0][i] = -3 * i;
	for (int i = 1; i < maxn; ++i)
		dp[i][0] = -3 * i;
	while (gets(a + 1)) {
		gets(b + 1);
		int n, m;
		for (n = 1; a[n]; ++n)
			for (m = 1; b[m]; ++m) {
				if (a[n] == b[m])
					dp[n][m] = 10 + dp[n-1][m-1];
				else
					dp[n][m] = -5 + dp[n-1][m-1];
				dp[n][m] = max(dp[n][m], -3 + dp[n-1][m]);
				dp[n][m] = max(dp[n][m], -3 + dp[n][m-1]);
			}
		bool neg = false;
		if (dp[n-1][m-1] < 0) {
			dp[n-1][m-1] *= -1;
			neg = true;
		}
		int ans = (dp[n - 1][m - 1] * 10 * 1000 / (n - 1) + 5) / 10;
		if (neg)
			putchar('-');
		printf("%d.%02d%%\n", ans / 100, ans % 100);
	}
}
