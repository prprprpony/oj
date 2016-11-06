#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int mul(int a, int b, int m) {return a * 1LL * b % m;}
int pow(int a, int x, int m)
{
	int ret = 1;
	for (a = mul(a, 1, m); x; x >>= 1, a = mul(a, a, m))
		if (x & 1)
			ret = mul(ret, a, m);
	return ret;
}
bool miller_rabin(int p)
{
	static const int b[] = {2, 7, 61};
	if (p <= 2 || !(p & 1)) return p == 2;
	int d = p - 1, s = 0;
	while (!(d & 1)) d >>= 1, ++s;
	for (auto a : b) {
		int x = a % p;
		if (!x || x == 1 || x == p - 1)
			continue;
		x = pow(x, d, p);
		if (x == 1 || x == p - 1)
			continue;
		for (int t = 0; t < s - 1; ++t) {
			x = mul(x, x, p);
			if (x == 1)
				return false;
			if (x == p - 1)
				break;
		}
		if (x != p - 1)
			return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		ll l, r;
		cin >> l >> r;
		int ans = 0;
		while (l <= r && l % 30)
			ans += miller_rabin(l++);
		const int step[] = {1,7,11,13,17,19,23,29};
		for (; l <= r; l += 30)
			for (auto s : step) {
				if (l + s > r) break;
				ans += miller_rabin(l + s);
			}
		cout << ans << '\n';
	}
}
