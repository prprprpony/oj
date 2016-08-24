#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 228;
int C[4][4];
int g[2][1024];
int dp[2][1024];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			cin >> C[i][j];
	int b = 0;
	for (int r = 1; r <= n; ++r) {
		b ^= 1;
		for (int c = 1; c <= m; ++c) {
			int & x = g[b][c];
			int & now = dp[b][c];
			cin >> x;
			++x;
			now = dp[b][c-1] + C[g[b][c-1]][x];
			now = max(now, dp[b^1][c] + C[g[b^1][c]][x]);
			now = max(now, dp[b^1][c-1] + C[g[b^1][c-1]][x]);
		}
	}
	cout << dp[b][m] << '\n';
}
