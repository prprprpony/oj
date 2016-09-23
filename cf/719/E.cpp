#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()
#define X first
#define Y second
// read integers
int RI() {return 0;}
template<typename T>
int RI(T & a)
{
	int c;
	int s = 1;
	while (!((c = getchar()) == '-' || isdigit(c) || c == EOF));
	if (c == EOF)
		return 0;
	if (c == '-') {
		s = -1;
		c = getchar();
	}
	a = 0;
	do {
		a = 10 * a + s * (c - '0');
	} while (isdigit(c = getchar()));
	return 1;
}
template<typename T, typename... Args>
int RI(T & a, Args & ... args) {return RI(a) ? 1 + RI(args...) : 0;}
//print integers, python style
template<typename T>
void __PI(T a)
{
	static const int maxd = 25;
	static char d[maxd];
	int i = maxd - 1;
	int s = a < 0 ? -1 : 1;
	do {
		d[--i] = s * (a % 10) + '0';
	} while (a /= 10);
	if (s < 0)
		d[--i] = '-';
	fputs(d + i, stdout);
}
template<char sep>
void __PSI() {}
template<char sep, typename T>
void __PSI(const T & a) {putchar(sep), __PI(a);}
template<char sep, typename T, typename... Args>
void __PSI(const T & a, const Args & ... args) {__PSI<sep, T>(a), __PSI<sep, Args...>(args...);}
template<char sep = ' ', char end = '\n', typename T, typename... Args>
void PI(const T & a, const Args & ... args) {__PI(a), __PSI<sep, Args...>(args...), putchar(end);}

const int M = 1e9 + 7;
inline int nml(int a) {return (a%M+M)%M;}
inline int mns(int a) {return M - a;}
inline int add(int a, int b) {return (a += b) < M ? a : a - M;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + M : a;}
inline int mul(int a, int b) {return a * 1LL * b % M;}
void exgcd(int a, ll & x, int b, ll & y, int & g)
{
	if (b) {
		exgcd(b, y, a%b, x, g);
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
struct mint
{
	int a, b; // a + b * sqrt(5)
	mint(int x, int y) : a(x), b(y) {}
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
		return mint(sub(a,x.a), sub(b, x.b));
	}
	mint operator * (mint x)
	{
		return mint(add(mul(a, x.a), mul(5, mul(b, x. b))), add(mul(a, x.b), mul(b, x.a)));
	}
	mint operator / (mint x)
	{
		int v = inv(sub(mul(x.a, x.a), mul(5, mul(x.b, x.b))));
		return *this * mint(x.a, mns(x.b)) * v;
	}
	mint operator *= (mint x)
	{
		return *this = *this * x;
	}
	bool operator != (mint x)
	{
		return a != x.a || b != x.b;
	}
};
int n, m;
mint phi = mint(1, 1) / 2;
mint phip = mint(1, mns(1)) / 2;

mint qpow(mint a, int x)
{
	mint ret(1,0);
	for (; x; a *= a, x>>=1)
		if (x & 1)
			ret *= a;
	return ret;
}

const int maxn = 1.1e5;
struct node
{
	mint tag;
	mint sum;
	node() : tag(1, 0), sum(0, 0) {};
};
int a[maxn];
node st[2][4 * maxn];

inline void upd(node & t, mint v)
{
	t.tag *= v;
	t.sum *= v;
}

inline void push(node * t, int o)
{
	if (t[o].tag != mint(1, 0)) {
		upd(t[o+o+1], t[o].tag);
		upd(t[o+o+2], t[o].tag);
		t[o].tag = mint(1, 0);
	}
}

inline void pull(node * t, int o)
{
	t[o].sum = t[o+o+1].sum + t[o+o+2].sum;
}

void build(node * t, int o, int l, int r, mint v)
{
	if (l == r) {
		t[o].sum = qpow(v, a[l]);
		return;
	}
	int m = (l+r)/ 2;
	build(t, o+o+1, l, m, v);
	build(t, o+o+2, m+1, r, v);
	pull(t, o);
}

void upd(node * t, int o, int l, int r, int i, int j, mint v) 
{
	if (j < l || r < i)
		return;
	if (i <= l && r <= j) {
		upd(t[o], v);
		return;
	}
	push(t, o);
	int m = (l + r) / 2;
	upd(t, o+o+1, l, m, i, j, v);
	upd(t, o+o+2, m+1, r, i, j, v);
	pull(t, o);
}

mint qry(node * t, int o, int l, int r, int i, int j)
{
	if (j < l || r < i)
		return mint(0, 0);
	if (i <= l && r <= j) {
		return t[o].sum;
	}
	int m = (l + r) / 2;
	push(t, o);
	return qry(t, o+o+1, l, m, i, j) + qry(t, o+o+2, m+1, r, i, j);;
}

int main()
{
	RI(n, m);
	rep(i, 1, n+1)
		RI(a[i]);
	build(st[0], 0, 1, n, phi);
	build(st[1], 0, 1, n, phip);
	while (m--) {
		int c, l, r, x;
		RI(c, l, r);
		switch (c) {
			case 1:
				RI(x);
				upd(st[0], 0, 1, n, l, r, qpow(phi, x));
				upd(st[1], 0, 1, n, l, r, qpow(phip, x));
				break;
			case 2:
				mint ans = (qry(st[0], 0, 1, n, l, r) - qry(st[1], 0, 1, n, l, r)) / mint(0, 1);
				PI(ans.a);
				break;
		}
	}
}
