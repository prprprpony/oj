#include <cstdio>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int maxk = 225;
int s[maxk], c[maxk][maxk];

inline int nml(ll a) {return ((a % M) + M) % M;}
void exgcd(int a, ll & x, int b, ll & y, int & g)
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
inline int inv(int a)
{
	ll x, y;
	int g;
	exgcd(M, x, a, y, g);
	return nml(y);
}
inline int add(int a, int b) {return (a += b) >= M ? a - M : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + M : a;}
inline int mul(int a, int b) {return a * 1LL * b % M;}
inline int _div(int a, int b) {return mul(a, inv(b));}
inline int mns(int a) {return M - a;}
struct mint
{
	int a, b; // a + b * sqrt(5)
	mint(int x, int y) : a(x), b(y) {}
	mint operator + (int x)
	{
		return mint(add(a, x), b);
	}
	mint operator - (int x)
	{
		return mint(sub(a, x), b);
	}
	mint operator * (int x)
	{
		return mint(mul(a, x), mul(b, x));
	}
	mint operator / (int x)
	{
		x = inv(x);
		return *this * x;
	}
	mint operator + (mint x)
	{
		return mint(add(a, x.a), add(b, x.b));
	}
	mint operator - (mint x)
	{
		return mint(sub(a, x.a), sub(b, x.b));
	}
	mint operator * (mint x)
	{
		return mint(add(mul(a, x.a), mul(5, mul(b, x.b))), add(mul(a, x.b), mul(b, x.a)));
	}
	mint operator / (mint x)
	{
		int v = sub(mul(x.a, x.a), mul(5, mul(x.b, x.b)));
		return *this * mint(x.a, mns(x.b)) / v;
	}
	mint operator *= (mint x)
	{
		return *this = *this * x;
	}
	mint operator += (mint x)
	{
		return *this = *this + x;
	}
	mint operator /= (int x)
	{
		return *this = *this / x;
	}
	bool operator != (int x)
	{
		return b || a != x;
	}
};

mint operator * (int x, mint y)
{
	return y * x;
}
mint operator / (int x, mint y)
{
	return mint(x, 0) / y;
}

void precalc(int k)
{
	s[1] = 1;
	for (int i = 2; i <= k; ++i)
		for (int j = i; j >= 1; --j)
			s[j] = add(mul(mns(i - 1), s[j]), s[j-1]);
	for (int i = 1; i <= k; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = add(c[i-1][j], c[i-1][j-1]);
	}
}

mint qpow(mint a, ll x)
{
	int sig = x < 0 ? -1 : 1;
	x *= sig;
	mint ret(1, 0);
	for ( ; x; x >>= 1, a *= a)
		if (x & 1)
			ret *= a;
	return (sig > 0) ? ret : (1 / ret);
}

int main()
{
	int k;
	ll l, r;
	scanf("%d%lld%lld", &k, &l, &r);
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

	mint isr5 = 1 / mint(0, 1);
	mint p = mint(1, 1) / 2;
	mint ip = 1 / p;
	mint p2 = p * p;
	mint pr3 = qpow(p, r + 3);
	mint pl2 = qpow(p, l + 2);
	mint ipr3 = 1 / pr3;
	mint ipl2 = 1 / pl2;
	mint pr3_2 = pr3 * pr3;
	mint pl2_2 = pl2 * pl2;
	mint rng(nml(r-l+1),0);

	mint ans(0, 0);
	mint v1 = isr5;
	mint v2 = ip;
	mint v3 = ipr3;
	mint v4 = ipl2;
	for (int j = 1; j <= k; ++j, v1 *= isr5, v2 *= ip, v3 *= ipr3, v4 *= ipl2) {
		mint sum(0, 0);
		int ne = (j & 1) ? mns(1) : 1;
		mint vv2 = v2;
		mint vv3 = v3;
		mint vv4 = v4;
		for (int m = 0; m <= j; ++m, ne = mul(ne, mns(1)), vv2 *= p2, vv3 *= pr3_2, vv4 *= pl2_2) {
			mint q = ne * vv2;
			mint qr3 = (((r+3)&1) ? ne : 1) * vv3;
			mint ql2 = (((l+2)&1) ? ne : 1) * vv4;
			sum += mul(ne, c[j][m]) * (q != 1 ? (qr3 - ql2) / (q - 1) : rng);
		}
		ans += s[j] * v1 * sum;
	}
	int ik = 1;
	for (int i = 1; i <= k; ++i)
		ik = mul(ik, i);
	printf("%d\n", _div(ans.a, ik));
}
