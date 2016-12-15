#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,s,e) for (int i = (s), __e = (e); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) for (int i = (s) - 1, __e = (e); i >= __e; --i)
#define PR(i,n) PER(i,n,0)
#define DO(n) REP(__i,0,n)
template<typename T>
void cmax(T & a, T b) {a = max(a, b);}
template<typename T>
void cmin(T & a, T b) {a = min(a, b);}

// data type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second

// STL container
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(), a.end()
#define CLR(a) a.clear()
#define BK(a) (a.back())
#define FT(a) (a.front())
#define DB(a) a.pop_back()
#define DF(a) a.pop_front()
#define PB push_back
#define EB emplace_back

/* reading input is now 20% cooler */
bool RD(void) {return true;}
bool RD(int & a)
{
	int c;
	while (!isdigit(c = getchar()));
	a = 0;
	do {
		a = 10 * a + c - '0';
	} while (isdigit(c = getchar()));
	return true;
}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* For it's time for you to fulfill your output */
void PT(const char * a) {fputs(a, stdout);}
void PT(const int a)
{
	static char buf[128];
	int t = a, i = 127;
	do {
		buf[--i] = t % 10 + '0';
	} while (t /= 10);
	PT(buf + i);
}
void PT(const ll a) {printf("%lld", a);}
void PT(const double a) {printf("%.16f", a);}
void PT(const char a) {putchar(a);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}

/* Good Luck && Have Fun ! */
const int M = 1e9+7, N = 1.12e5, D = __lg(N) + 1;
int a[N], v[2][N], ct[N], sa[N], *rk, ht[N], st[D][N];
inline int mul(int a, int b) {return a * 1LL * b % M;}
int qpow(int a, int x)
{
	int ret = 1;
	for ( ; x; x >>= 1, a = mul(a,a))
		if (x & 1)
			ret = mul(ret, a);
	return ret;
}
void build_sa(int * s, int n, int m)
{
	int *x = v[0], *y = v[1];
	fill_n(ct, m, 0);
	RP(i,n) ++ct[x[i] = s[i]];
	REP(i,1,m) ct[i] += ct[i-1];
	PR(i,n) sa[--ct[x[i]]] = i;
	for (int k = 1, p = 0; k < n; k <<= 1, p = 0) {
		REP(i,n-k,n) y[p++] = i;
		RP(i,n) if (sa[i] >= k) y[p++] = sa[i] - k;
		fill_n(ct, m, 0);
		RP(i,n) ++ct[x[y[i]]];
		REP(i,1,n) ct[i] += ct[i-1];
		PR(i,n) sa[--ct[x[y[i]]]] = y[i];
		swap(x, y);
		x[sa[0]] = 0;
		p = 1;
		REP(i,1,n) x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i] + k] == y[sa[i-1] + k] ? p-1 : p++;
		if ((m = p) == n) break;
	}
	rk = x;
	int h = ht[0] = 0;
	RP(i,n) {
		if (!rk[i]) {h = 0; continue;}
		while (s[i + h] == s[sa[rk[i] - 1] + h]) ++h;
		ht[rk[i]] = h ? h-- : 0;
	}
}
void build_st(int * x, int n)
{
	RP(i,n) st[0][i] = x[i];
	for (int k = 1; (1 << k) <= n; ++k)
		RP(i,n - (1 << k) + 1)
			st[k][i] = min(st[k-1][i], st[k-1][i+(1<<(k-1))]);
}
int qry(int l, int r) // [l,r)
{
	int k = __lg(r - l);
	return min(st[k][l], st[k][r - (1<<k)]);
}
int main()
{
	int n,q;
	RD(n,q);
	RP(i,n) {
		RD(a[i]);
		a[i] = qpow(a[i], (M-1)>>1) == 1 ? 1 : 2;
	}
	a[n++] = 0;
#ifdef PP
	RP(i,n)
		PT(a[i]), PT(" \n"[i == n - 1]);
#endif
	build_sa(a,n,3);
	build_st(ht,n);
	while (q--) {
		int i,j;
		RD(i,j);
#ifdef PP
PL('\n',i,j);
#endif
		if (i == j) {
			PL(n - 1 - i);
			continue;
		}
		i = rk[i], j = rk[j];
		if (j < i)
			swap(i, j);
		PL(qry(i+1,j+1));
	}
}
