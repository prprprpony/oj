#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull dp[99];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	dp[0] = 1;
	for (int i = 1; i <= m; ++i) {
		dp[i] = dp[i-1];
		for (int j = 1; j <= n && j <= i; ++j)
			dp[i] += i - j - 1 >= 0 ? dp[i-j-1] : 1;
	}
	cout << dp[m] << '\n';
}
