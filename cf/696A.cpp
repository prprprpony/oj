#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> a;
void add(ll u, ll v, int w)
{
	while (u != v) {
		if (u < v)
			swap(u, v);
		a[u] += w;
		u >>= 1;
	}
}
ll query(ll u, ll v)
{
	ll ret = 0;
	while (u != v) {
		if (u < v)
			swap(u, v);
		ret += a[u];
		u >>= 1;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int e, w;
	   	ll v, u;
		cin >> e >> v >> u;
		switch (e) {
		case 1:
			cin >> w;
			add(u, v, w);
			break;
		case 2:
			cout << query(u, v) << '\n';
			break;
		}
	}
}
