#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
typedef long long ll;
void exgcd(ll a, ll & x, ll b, ll & y, ll & g)
{
	if (b) {
		exgcd(b,y,a%b,x,g);
		y -= a/b*x;
	} else {
		x = 1;
		y = 0;
		g = a;
	}
}
void gqr(ll a,ll b,ll & q, ll & r)
{
	q = a/b;
	r = a%b;
}
ll fl(ll a, ll b, ll c)
{
	ll q0,r0,q1,r1;
	gqr(a,c,q0,r0);
	gqr(b,c,q1,r1);
	ll ret = c*q0*q1 + q0*r1 + q1*r0;
	ll r = r0 * r1;
	if (r < 0)
		ret += r/c;
	else
		ret += (r+c-1)/c;
	return ret;
}
/*
istream& operator >> (istream& in, ll & x)
{
	lo y;
	in >> y;
	x = y;
	return in;
}
ostream& operator << (ostream& out, ll x)
{
	static const lo B = 1e9;
	if (x < 0) {
		out << '-';
		x = -x;
	}
	if (x >= B)
		out << (lo)(x/B) << setw(9) << setfill('0') << (lo)(x%B);
	else
		out << (lo)(x);
	return out;
}
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		ll x,y,p,q;
		cin >> x >> y >> p >> q;
		if (!p) {
			cout << (!x ? "0\n" : "-1\n");
			continue;
		}
		if (p == q) {
			cout << (x == y ? "0\n" : "-1\n");
			continue;
		}
		ll c = q*x-p*y, x0, y0, g;
		exgcd(p,x0,q,y0,g);
		y0*=-1;
		if (c % g) {
			cout << "-1\n";
			continue;
		}
		ll a = p/g, b = q/g;
		c /= g;
		ll k = max(fl(c,y0-x0,b-a), fl(-c,y0,a));
		cout << c*x0+b*k << '\n';
	}
}
