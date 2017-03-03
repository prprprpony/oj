#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) for (int i = (s) - 1, __e = (e); i >= __e; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) for (int i = (a), __e = (b); i <= __e; ++i)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,s,e) for (int i = (s), __e = (e); i >= __e; --i)
#define PR1(i,n) PER1(i,n,1)
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

/* Reading input is now 20% cooler! */
const int BS = 2e7;
char __ibf[BS];
int __ibfp;
int __SZ;
void inbf()
{
	while (fgets(__ibf + __ibfp, BS - __ibfp, stdin) != NULL)
		for (;__ibf[__ibfp];++__ibfp);
	__SZ = __ibfp;
	__ibfp = 0;
}
inline int bfgc() {return __ibfp < __SZ ? __ibf[__ibfp++] : EOF;}
bool RD(void) {return true;}
bool RD(int & a)
{
	a = 0;
	int c;
	while (!isdigit(c = bfgc()));
	do {
		a = 10 * a + c - '0';
	} while (isdigit(c = bfgc()));
	return true;
}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)
#define DRIII(a,b,c) DRI(a); DRII(b,c)
#define DRIIII(a,b,c,d) DRI(a); DRIII(b,c,d)

/* For it's time for you to fulfill your output. */
char __bf[BS];
int __bfp;
void clbf() {fputs(__bf,stdout);__bfp=0;}
void PT(const char * a) {for(int i=0;a[i];++i) __bf[__bfp++] = a[i];}
void PT(const char a) {__bf[__bfp++] = a;}
void PT(const int a)
{
	int t = a;
	static char buf[87];
	int i = 86;
	do {
		buf[--i] = t%10+'0';
	} while (t /= 10);
	PT(buf + i);
}
void PT(const ll a) {printf("%lld", a);}
void PT(const double a) {printf("%.16f", a);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}

/* Good Luck && Have Fun ! */
const int N = 1e5;
pii t[N<<2];
#define LC o+o+1,l,m
#define RC o+o+2,m,r
inline void asn(int o,int l,int r)
{
	t[o] = {r-l,1};
}
inline void push(int o,int l,int m,int r)
{
	if (t[o].S) {
		asn(LC);
		asn(RC);
		t[o].S = 0;
	}
}
inline void pull(int o)
{
	t[o].F = t[o+o+1].F + t[o+o+2].F;
}
int qry(int o,int l,int r,int i,int j)
{
	if (r <= i || j <= l)
		return 0;
	if (i <= l && r <= j)
		return t[o].F;
	int m = (l + r) / 2;
	push(o,l,m,r);
	return qry(LC,i,j) + qry(RC,i,j);
}
int add(int o,int l,int r,int i,int j,int k)
{
	if (r <= i || j <= l)
		return k;
	if (i <= l && r <= j && r - l - t[o].F <= k) {
		k -= (r - l - t[o].F);
		asn(o,l,r);
		return k;
	}
	int m = (l + r) / 2;
	push(o,l,m,r);
	k = add(RC,i,j,k);
	if (k)
		k = add(LC,i,j,k);
	pull(o);
	return k;
}
struct itm
{
	int a,b,c;
	bool operator < (const itm & rhs) const
	{
		return b < rhs.b;
	}
} x[N];
int main()
{
	inbf();
	int n;
	while (RD(n) && n) {
		int l=N+87,r=-87;
		RP(i,n) {
			RD(x[i].a, x[i].b, x[i].c);
			cmin(l,x[i].a);
			cmax(r,x[i].b);
		}
		sort(x,x+n);
		fill_n(t,4*(r-l),pii{0,0});
		RP(i,n) {
			int v = qry(0,l,r,x[i].a,x[i].b);
			if (v < x[i].c) {
				v = x[i].c - v;
				add(0,l,r,x[i].a,x[i].b,v);
			}
		}
		PL(qry(0,l,r,l,r));
	}
	clbf();
}
