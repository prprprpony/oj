#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 87;
ll dp[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	ll n,x,y;
	cin >> n >> x >> y;
	dp[1] = x;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i-1] + x;
		if (!(i&1))
			dp[i] = min(dp[i], dp[i>>1] + y);
		else
			dp[i] = min(dp[i], dp[(i+1)>>1] + y + x);
	}
	cout << dp[n] << '\n';
}
