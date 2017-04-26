#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a), _B(b); i < _B; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1), _B(b); i >= _B; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
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

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {}
template<typename T, typename ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		switch (*s) {
		case '(':
		case '[':
		case '{':
			++c;
			break;
		case ')':
		case ']':
		case '}':
			--c;
			break;
		}
	}
	cerr<<" = "<<a;
	if (*s) {
		cerr<<", ";
		_BG(++s,b...);
	} else
		cerr<<endl;
}
#define BG(...) do { \
	cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
	_BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)

/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define RI(a) int a; RD(a)
#define RII(a,b) RI(a); RI(b)
#define RIII(a,b,c) RI(a); RII(b,c)
#define RIIII(a,b,c,d) RI(a); RIII(b,c,d)

/* For it's time for you to fulfill your output. */
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
void PT(const double a) {printf("%.16f", a);}
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}

/* The line will last forever! */
template<char sep = ' ',char end = '\n'>
void PL(void) {if (end) PT(end);}
template<char sep = ' ',char end = '\n',typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}

/* Good Luck && Have Fun ! */
const int N = 5e5 + 87;
struct milf // modular integer: long with float
{
	static const int M = 1e9+7;
	int k;
	double f;
	milf() {}
	milf(int a) : k(a), f(log(a)) {}
	milf(int a,double b) : k(a), f(b) {}
	milf operator * (const milf & a)
	{
		ll v = k; v *= a.k;
		return milf(v%M,f+a.f);
	}
	milf operator *= (const milf & a)
	{
		return *this = *this * a;
	}
	bool operator < (const milf & a) const
	{
		return f < a.f;
	}
};
struct node
{
	milf pre, post, now;
} t[N*4];
int a[N],b[N];
void asn(int o,int i)
{
	t[o].pre = milf(a[i]);
	t[o].post = milf(1);
	t[o].now = milf(b[i]);
}
#define LC o+o+1,l,m
#define RC o+o+2,m,r
void pull(int o)
{
	int l = o+o+1, r = o+o+2;
	if (t[l].now < t[l].post * t[r].pre * t[r].now) {
		t[o] = t[r];
		t[o].pre *= t[l].pre * t[l].post;
	} else {
		t[o] = t[l];
		t[o].post *= t[r].pre * t[r].post;
	}
}
void bld(int o,int l,int r)
{
	if (r - l == 1) {
		asn(o,l);
		return;
	}
	int m = l + ((r-l)>>1);
	bld(LC);
	bld(RC);
	pull(o);
}
void upd(int o,int l,int r,int i)
{
	if (r - l == 1) {
		asn(o,l);
		return;
	}
	int m = l + ((r-l)>>1);
	if (i < m)
		upd(LC,i);
	else
		upd(RC,i);
	pull(o);
}
int main()
{
	RI(T);
	while (T--) {
		RI(n);
		RP(i,n) RD(a[i]);
		RP(i,n) RD(b[i]);
		bld(0,0,n);
		PL((t[0].pre * t[0].now).k);
		RI(m);
		while (m--) {
			RIII(k,p,v);
			if (k == 1)
				a[p] = v;
			else
				b[p] = v;
			upd(0,0,n,p);
			PL((t[0].pre * t[0].now).k);
		}
	}
}
