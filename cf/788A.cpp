#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 87;
int a[N], n;
ll f()
{
	ll s = a[0], v = a[0];
	for (int i = 1; i < n; ++i) {
		if (s < 0)
			s = 0;
		s += a[i];
		v = max(v, s);
	}
	return v;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	--n;
	for (int i = 0; i < n; ++i)
		a[i] = abs(a[i+1] - a[i]) * ((i&1) ? -1 : 1);
	ll ans = f();
	for (int i = 0; i < n; ++i)
		a[i] *= -1;
	ans = max(ans, f());
	cout << ans << '\n';
}
