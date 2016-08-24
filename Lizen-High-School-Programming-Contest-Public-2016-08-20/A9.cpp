#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
void movein(int);
void moveout(int);
void exgcd(int a, ll & x, int b, ll & y, ll & g)
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
int inv(int a)
{
	ll x, y, g;
	exgcd(a, x, M, y, g);
	assert(g == 1);
	return ((x % M) + M) % M;
}
inline int mul(int a, int b) {return a * 1LL * b % M;}
inline int add(int a, int b) {return (a += b) >= M ? a - M : a;}
inline int _sub(int a, int b) {return (a -= b) < 0 ? a + M : a;}
inline int frac(int a, int b) {return mul(a, inv(b));}
int qpow(int a, ll x)
{
	int r = 1;
	for ( ; x; x >>= 1, a = mul(a, a))
		if (x & 1)
			r = mul(r, a);
	return r;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	cout << frac(add(qpow(2, n+1), M - 2 + (n & 1)), 3) << '\n';
	if (n <= 10)
		moveout(n);
}
void moveout(int x) // remove [1,x]
{
	if (x > 0) {
		moveout(x-2);
		cout << "Move ring " << x << " out\n";
		movein(x-2);
		moveout(x-1);
	}
}
void movein(int x) // put [1,x] back
{
	if (x > 0) {
		movein(x-1);
		moveout(x-2);
		cout << "Move ring " << x << " in\n";
		movein(x-2);
	}
}

