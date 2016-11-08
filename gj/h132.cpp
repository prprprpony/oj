// need big integer?
#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,s,e) for (int i = (s), __e = (e); i != __e; ++i)
const ll maxa = 955049953;
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
void exgcd(ll a, ll & x, ll b, ll & y, ll & g)
{
	if (b) {
		exgcd(b, y, a % b, x, g);
		y -= a / b * x;
	} else {
		x = 1;
		y = 0;
		g = a;
	}
}
ll inv(ll a, ll m) 
{
	ll x, y, g;
	exgcd(m,x,a,y,g);
/* cannot use assert >_< */
	if (!(g == 1)) return 87 / (2 + 2 == 5);
	return mod(y, m);
}
inline ll sub(ll a, ll b, ll m) {return (a -= b) < 0 ? a + m : a;}
inline ll mul(ll a, ll b, ll m) {return a * b % m;}
inline ll _div(ll a, ll b, ll m) {return mul(a, inv(b, m), m);}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		ll m1, a1;
		cin >> m1 >> a1;
		bool large = false;
		rep(i,1,n) {
			ll m2, a2;
			cin >> m2 >> a2;
			if (a1 >= maxa)
				continue;
			if (large) {
				if (a1 % m2 != a2)
					a1 = maxa;
				continue;
			}
			ll y = _div(sub(a2, mod(a1, m2), m2), mod(m1, m2), m2);
			a1 += m1 * y;
			m1 *= m2;
			a1 = mod(a1, m1);
			if (m1 >= maxa)
				large = true;
			/*
			   m1 y + a1 = m2 k + a2
			   m1 y = a2 - a1 mod m2
			   y = (m1)^(-1) * (a2 - a1) mod m2
		   */
		}
		cout << (a1 >= maxa ? -1 : a1) << '\n';
	}
}
