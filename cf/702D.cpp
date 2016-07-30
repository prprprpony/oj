#include <cstdio>
using namespace std;
typedef long long ll;
inline void rll(ll & a) {scanf("%lld", &a);}
int main()
{
	ll d, k, a, b, t;
	ll ans;
	rll(d), rll(k), rll(a), rll(b), rll(t);
	if (d <= k)
		ans = a * d;
	else {
		ans = a * k;
		d -= k;
		if (t + a * k < b * k) {
			ans += d / k * (t + a * k);
			d %= k;
		} else {
			ans += d * b;
			d = 0;
		}
		if (t + a * d < b * d)
			ans += t + a * d;
		else
			ans += d * b;
	}
	printf("%lld\n", ans);
}
