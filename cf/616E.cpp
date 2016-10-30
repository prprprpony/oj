#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int INV2 = 5e8 + 4;
inline ll mul(ll a, ll b) {return a * b % M;}
inline ll sub(ll a, ll b) {return (a -= b) < 0 ? a + M : a;}
inline ll add(ll a, ll b) {return (a += b) >= M ? a - M : a;}
int main()
{
	ll n, m, mi;
	scanf("%lld%lld", &n, &m);
	ll ans = mul(n % M, m % M);
	m = min(n, m);
	mi = m;
	for (ll v = 1; v * v <= n; ++v) {
		ll l = n / (v + 1), r = min(m, n / v);
		if (l >= r)
			continue;
		mi = l;
		l %= M, r %= M;
		ans = sub(ans, mul(v, mul(mul(add(add(l, 1), r), sub(r, l)), INV2)));
	}
	for (ll i = 1; i <= mi; ++i)
		ans = sub(ans, mul((n / i) % M, i % M));
	printf("%lld\n", ans);
}
