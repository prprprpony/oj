#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 556655;
ll c[maxn], sum[maxn], dp[maxn];
inline ll sqr(ll x) {return x * x;}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = n; i >= 1; --i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
		sum[i] = c[i] + sum[i - 1];
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i-1] + sum[i-1] - 1;
		for (int j = i - 2; j >= max(0, i - k); --j)
			dp[i] = max(dp[i], dp[j] + sum[j] - sqr(i - j));
	}
	cout << dp[n] << '\n';
}
