#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
///*
	int ans = 0, s = 0, la = 0;
	for (int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		if (s < c - la) {
			s += la;
			++ans;
		}
		la = c;
	}
	cout << ans << '\n';
	return;
//*/
/*  
	// O(N^2) dp
	static const int N = 1087, inf = 2.1e9;
    static int c[N], dp[N];
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	c[n+1] = inf;
	fill_n(dp+1,n,inf);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j >= 1; --j)
			if (dp[j-1] < c[i] && dp[j-1] < c[i+1] - c[i])
				dp[j] = min(dp[j], dp[j-1] + c[i]);
	for (int i = n; i >= 1; --i)
		if (dp[i] != inf) {
			cout << i << '\n';
			return;
		}
*/
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
		solve();
}
