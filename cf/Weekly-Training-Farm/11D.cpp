#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 42;
const int inf = 1e9;
int dp[maxn];
int main()
{
	fill_n(dp, maxn, inf);
	dp[0] = 0;
	for (int i = 1, v = 1; v < maxn; ++i, v += i)
		for (int j = v; j < maxn; ++j)
			dp[j] = min(dp[j], dp[j - v] + i);
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}
