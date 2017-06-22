#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m=2;
	cin >> n;
	for (ll k = 1; k <= n; ++k) {
		ll v = k * (k+1) * (k+1), g = 1;
		for ( ; g*g*v < m; ++g);
		cout << g*g*v-m << '\n';
		m = k*g;
	}
}
