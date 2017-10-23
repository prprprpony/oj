#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87,B = 17;
const int U = (1<<B) - 1;
int a[N],dp[1<<B];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[a[i]] = a[i];
	}
	for (int s = U; s > 0; --s) if (dp[s])
		for (int i = 0; i < B; ++i) if (1<<i&s)
			dp[1<<i^s] = 1<<i^s;
	for (int s = 1; s <= U; ++s)
		for (int i = 0; i < B; ++i) if (1<<i&s)
			dp[s] = max(dp[s], dp[1<<i^s]);
	int m = 0;
	for (int i = 0; i < n; ++i)
		m = max(m, a[i] | dp[~a[i] & U]);
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < n; ++i)
		++dp[a[i]];
	for (int i = 0; i < B; ++i)
		for (int s = 0; s <= U; ++s) 
			if (1<<i & ~s)
				dp[s] += dp[1<<i^s];
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += dp[a[i] & m ^ m];
	cout << m << ' ' << (ans - dp[m]) / 2 << '\n';
}
