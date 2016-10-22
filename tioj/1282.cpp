#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.12e5;
const int maxb = sqrt(maxn) + 0.5;
const ll inf = 1LL << 62;
int N, Q, SZ;
struct seg
{
	ll mn, gd, k;
};
ll a[maxn];
seg b[maxb];
#ifdef PP
// binary gcd seems to be slower
ll gcd(ll a, ll b)
{
	if (!a || !b)
		return a ? a : b;
	int p = 0;
	while (!(a & 1) && !(b & 1))
		a >>= 1, b >>= 1, ++p;
	while (b) {
		while (!(a & 1))
			a >>= 1;
		while (!(b & 1))
			b >>= 1;
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a << p;
}
#else
#define gcd __gcd
#endif
void calc(int j)
{
	int l = j * SZ;
	int r = min(N, l + SZ);
	seg & now = b[j];
	if (now.k) {
		for (int i = l; i < r; ++i)
			a[i] += now.k;
		now.k = 0;
	}
	now.mn = inf;
	for (int i = l; i < r; ++i)
		now.mn = min(now.mn, a[i]);
	now.gd = now.k = 0;
	for (int i = l; i < r && now.gd != 1; ++i)
		now.gd = gcd(now.gd, a[i] - now.mn);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	SZ = sqrt(N) + 0.5;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int j = 0; j * SZ < N; ++j)
		calc(j);
	while (Q--) {
		int c, l, r;
		ll k, ans;
		cin >> c >> l >> r;
		--l, --r;
		int fi = l / SZ, la = r / SZ;
		switch (c) {
		case 1:
			cin >> k;
			if (fi == la) {
				for ( ; l <= r; ++l)
					a[l] += k;
				calc(fi);
			} else {
				for ( ; l < (fi + 1) * SZ ; ++l)
					a[l] += k;
				for ( ; r >= la * SZ; --r)
					a[r] += k;
				calc(fi);
				calc(la);
				for (++fi; fi < la; ++fi)
					b[fi].k += k;
			}
			break;
		case 2:
			ans = 0;
			if (fi == la) {
				for ( ; l <= r && ans != 1; ++l)
					ans = gcd(ans, a[l] + b[fi].k);
			} else {
				for ( ; l < (fi + 1) * SZ && ans != 1; ++l)
					ans = gcd(ans, a[l] + b[fi].k);
				for ( ; r >= la * SZ && ans != 1; --r)
					ans = gcd(ans, a[r] + b[la].k);
				for (++fi; fi < la && ans != 1; ++fi)
					ans = gcd(ans, gcd(b[fi].mn + b[fi].k, b[fi].gd));
			}
			cout << ans << '\n';
			break;
		}
	}
}
