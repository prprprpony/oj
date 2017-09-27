#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
ll a[N], pr[N], po[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,p,q,r;
	cin >> n >> p >> q >> r;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pr[i] = max(a[i] * p, i ? pr[i-1] : LLONG_MIN);
	}
	po[n-1] = r * a[n-1];
	for (int i = n - 2; i >= 0; --i) {
		po[i] = max(po[i+1], a[i] * r);
	}
	ll ans = LLONG_MIN;
	for (int i = 0; i < n; ++i)
		ans = max(ans, pr[i] + q * a[i] + po[i]);
	cout << ans << '\n';
}
