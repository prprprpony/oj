#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int D = 60;
ll qry(ll a,ll x)
{
	ll ans = 0;
	for (int i = D-1; i >= 0; --i)
		if ((a>>i&1) && !(x>>i&1))
			ans += 1LL << __builtin_popcountl(((1LL<<i)-1) & ~x);
		else if (!(a>>i&1) && (x>>i&1))
			break;
	ans += (a&x) == x;
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		ll a, b, x;
		cin >> a >> b >> x;
		cout << qry(b,x) - qry(a-1,x) << '\n';
	}
}
