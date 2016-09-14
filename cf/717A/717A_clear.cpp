#include <cstdio>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
const int maxk = 225;
ll s[maxk], c[maxk][maxk];

inline ll nml(ll a) {return ((a % M) + M) % M;}
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
inline ll inv(ll a)
{
	ll x, y, g;
	exgcd(M, x, a, y, g);
	return nml(y);
}
inline ll add(ll a, ll b) {return (a += b) >= M ? a - M : a;}
inline ll sub(ll a, ll b) {return (a -= b) < 0 ? a + M : a;}
inline ll mul(ll a, ll b) {return a * b % M;}
inline ll _div(ll a, ll b) {return mul(a, inv(b));}
inline ll mns(ll a) {return M - a;}
struct mll
{
	ll a, b; // a + b * sqrt(5)
	mll(ll x, ll y) : a(nml(x)), b(nml(y)) {}
	mll operator + (ll x)
	{
		return mll(add(a, x), b);
	}
	mll operator - (ll x)
	{
		return mll(sub(a, x), b);
	}
	mll operator * (ll x)
	{
		return mll(mul(a, x), mul(b, x));
	}
	mll operator / (ll x)
	{
		x = inv(x);
		return *this * x;
	}
	mll operator + (mll x)
	{
		return mll(add(a, x.a), add(b, x.b));
	}
	mll operator - (mll x)
	{
		return mll(sub(a, x.a), sub(b, x.b));
	}
	mll operator * (mll x)
	{
		return mll(add(mul(a, x.a), mul(5, mul(b, x.b))), add(mul(a, x.b), mul(b, x.a)));
	}
	mll operator / (mll x)
	{
		ll v = sub(mul(x.a, x.a), mul(5, mul(x.b, x.b)));
		return *this * mll(x.a, mns(x.b)) / v;
	}
	mll operator *= (mll x)
	{
		return *this = *this * x;
	}
	mll operator += (mll x)
	{
		return *this = *this + x;
	}
	mll operator /= (ll x)
	{
		return *this = *this / x;
	}
	bool operator != (ll x)
	{
		return b || a != x;
	}
};

mll operator * (ll x, mll y)
{
	return y * x;
}
mll operator / (ll x, mll y)
{
	return mll(x, 0) / y;
}

void precalc(ll k)
{
	s[1] = 1;
	for (ll i = 2; i <= k; ++i)
		for (ll j = i; j >= 1; --j)
			s[j] = add(mul(mns(i - 1), s[j]), s[j-1]);
	for (ll i = 1; i <= k; ++i) {
		c[i][0] = c[i][i] = 1;
		for (ll j = 1; j < i; ++j)
			c[i][j] = add(c[i-1][j], c[i-1][j-1]);
	}
}

mll qpow(mll a, ll x)
{
	ll sig = x < 0 ? -1 : 1;
	x *= sig;
	mll ret(1, 0);
	for ( ; x; x >>= 1, a *= a)
		if (x & 1)
			ret *= a;
	return (sig > 0) ? ret : (1 / ret);
}

int main()
{
	ll k, l, r;
	scanf("%lld%lld%lld", &k, &l, &r);
	{
		int a = 0, b = 1, i = 1;
		for (;b < k; ++i, b += a, a = b - a);
		if (l + 2 < i)
			l = i - 2;
		if (r < l) {
			puts("0");
			return 0;
		}
	}
	precalc(k);
	mll isr5 = 1 / mll(0, 1);
	mll phi = mll(1, 1) / 2;
	mll phi2 = phi * phi;

	mll ans(0, 0);

	mll v1 = isr5;
	for (ll j = 1; j <= k; ++j, v1 *= isr5) {
		mll sum(0, 0);
		mll v2 = qpow(phi, -j);
		ll ne = (j & 1) ? mns(1) : 1;
		for (ll m = 0; m <= j; ++m, ne = mul(ne, mns(1)), v2 *= phi2) {
			mll q = ne * v2;
			sum += mul(ne, c[j][m]) * (q != 1 ? qpow(q, l + 2) * (qpow(q, r - l + 1) - 1) / (q - 1) : mll(r - l + 1, 0));
		}
		ans += s[j] * v1 * sum;
	}
	ll ik = 1;
	for (ll i = 1; i <= k; ++i)
		ik = mul(ik, i);
	ans /= ik;
	printf("%lld\n", ans.a);
}