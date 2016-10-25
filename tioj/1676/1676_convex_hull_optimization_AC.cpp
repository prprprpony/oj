#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 556655;
ll c[maxn], sum[maxn], dp[maxn];
struct line
{
	ll i, a, b;
	line(ll _i, ll _a, ll _b) : i(_i), a(_a), b(_b) {}
	ll operator () (ll x) {return a * x + b;}
};
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
	deque<line> dk;
	dk.push_back({0, 0, 0});
	for (ll i = 1; i <= n; ++i) {
		while (dk.size() && dk[0].i < i - k)
			dk.pop_front();
		while (dk.size() >= 2 && dk[0](i) <= dk[1](i))
			dk.pop_front();
		dp[i] = -i * i + dk[0](i);
		line now(i, 2 * i, dp[i] + sum[i] - i * i);
		int r = dk.size() - 1;
		while (r >= 1
			&& (dk[r].b - now.b) <= (dk[r-1].i + k) * (now.a - dk[r].a)
			&& (dk[r].b - now.b) * (dk[r].a - dk[r-1].a) <= (dk[r-1].b - dk[r].b) * (now.a - dk[r].a))
				dk.pop_back(), --r;
		dk.push_back(now);
	}
	cout << dp[n] << '\n';
}
