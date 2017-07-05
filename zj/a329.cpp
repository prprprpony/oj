#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 6, M = 1234567;
vector<int> g[N];
int dp[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		g[i].resize(k);
		for (int & x : g[i])
			cin >> x;
	}
	dp[n] = 1;
	for (int i = n - 1; i >= 1; --i)
		for (int j : g[i])
			dp[i] = (dp[i] + dp[j]) % M;
	cout << dp[1] << '\n';
}
