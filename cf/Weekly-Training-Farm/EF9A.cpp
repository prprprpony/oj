#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		ll ans = r;
		if (l < r) {
			ll a = __lg(l), b = __lg(r);
			if (r != (1LL << (b+1)) - 1) {
				if (a != b) {
					ans = (1LL << b) - 1;
				} else {
					ull p;
					for (p = 1LL << (b - 1); p >= 2 && !((r & p) ^ (l & p)); p >>= 1);
					if (p >= 2 && (r & (p << 1) - 1) != (p << 1) - 1)
						ans = (r & ~((p << 1) - 1)) | (p - 1);
				}
			}
		}
		printf("%lld\n", ans);
	}
}
