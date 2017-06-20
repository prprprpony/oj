#include<bits/stdc++.h>
using namespace std;
const int N = 106;
int g[N][N], r[N], c[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> g[i][j];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += g[i][1];
	for (int i = 1; i <= m; ++i)
		ans += g[1][i];
	ans -= n * g[1][1];
	int lo = 0, hi = 500;
	for (int i = 1; i <= m; ++i)
		hi = min(hi, g[1][i]);
	for (int i = 1; i <= n; ++i)
		lo = max(lo, g[1][1] - g[i][1]);
	if (lo > hi) {
		cout << "-1\n";
		return 0;
	}
	r[1] = n < m ? hi : lo;
	ans += (n - m) * r[1];
	for (int i = 1; i <= m; ++i)
		c[i] = g[1][i] - r[1];
	for (int i = 2; i <= n; ++i)
		r[i] = g[i][1] - c[1];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (r[i] + c[j] != g[i][j]) {
				cout << "-1\n";
				return 0;
			}
	cout << ans << "\n";
	for (int i = 1; i <= n; ++i)
		while (r[i]--)
			cout << "row " << i << '\n';
	for (int i = 1; i <= m; ++i)
		while (c[i]--)
			cout << "col " << i << '\n';
}
