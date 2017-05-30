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
const int N = 1e5 + 87;
typedef pair<double,double> pd;
pd t[N*4];
double p[N];
#define LC o+o+1,l,m
#define RC o+o+2,m,r
#define L t[o+o+1]
#define R t[o+o+2]
pd meld(pd x,pd y)
{
	return {x.F * y.F / (1 - (1 - y.F) * x.S), y.S + (1-y.S)*x.S*y.F/(1-(1-y.F)*x.S)};
}
void bld(int o,int l,int r)
{
	if (r - l == 1) {
		t[o] = {p[l],p[l]};
		return;
	}
	int m = (l + r) / 2;
	bld(LC);
	bld(RC);
	t[o] = meld(L,R);
}
void upd(int o,int l,int r,int i,double v)
{
	if (r - l == 1) {
		t[o] = {v,v};
		return;
	}
	int m = (l + r) / 2;
	if (i < m)
		upd(LC,i,v);
	else
		upd(RC,i,v);
	t[o] = meld(L,R);
}
pd qry(int o,int l,int r,int i,int j)
{
	if (i <= l && r <= j)
		return t[o];
	int m = (l + r) / 2;
	if (j <= m)
		return qry(LC,i,j);
	if (m <= i)
		return qry(RC,i,j);
	return meld(qry(LC,i,j),qry(RC,i,j));
}
int main()
{
	RII(n,q);
	RP(i,n) {
		RII(a,b);
		p[i] = a * 1.0 / b;
	}
	bld(0,0,n);
	DO(q) {
		RI(t);
		if (t == 1) {
			RIII(i,a,b);
			--i;
			upd(0,0,n,i,a * 1.0 / b);
		} else {
			RII(l,r);
			--l;
			PL(qry(0,0,n,l,r).F);
		}
	}
}
