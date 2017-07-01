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
const ll inf = 1e15;
int n;
pair<pii,int> e[N];
vi g[N*4];
struct node
{
	ll tg;
	pair<ll,int> p;
} t[N*4];
void add(int o,int l,int r,int i,int j,int x)
{
	if (r <= i || j <= l)
		return;
	if (i <= l && r <= j) {
		g[o].PB(x);
		return;
	}
	int m = (l + r) / 2;
	add(o+o+1,l,m,i,j,x);
	add(o+o+2,m,r,i,j,x);
}
void pull(int o)
{
	t[o].p = {inf,n};
	if (t[o+o+1].p.S < n)
		cmin(t[o].p, t[o+o+1].p);
	if (t[o+o+2].p.S < n)
		cmin(t[o].p, t[o+o+2].p);
}
void bld(int o,int l,int r)
{
	t[o].tg = inf;
	if (r - l == 1) {
		t[o].p = {inf,l};
		return;
	}
	int m = (l + r) / 2;
	bld(o+o+1,l,m);
	bld(o+o+2,m,r);
	pull(o);
}
void upd(int o,ll x)
{
	if (x < t[o].tg) {
		t[o].tg = x;
		if (t[o].p.S < n)
			cmin(t[o].p.F, x);
	}
}
void push(int o)
{
	upd(o+o+1,t[o].tg);
	upd(o+o+2,t[o].tg);
}
void upd(int o,int l,int r,int i,int j,ll x)
{
	if (r <= i || j <= l || t[o].tg <= x)
		return;
	if (i <= l && r <= j) {
		upd(o,x);
		return;
	}
	int m = (l + r) / 2;
	push(o);
	upd(o+o+1,l,m,i,j,x);
	upd(o+o+2,m,r,i,j,x);
	pull(o);
}
void del(int o,int l,int r,int i)
{
	if (r - l == 1) {
		t[o].p.S = n;
		return;
	}
	int m = (l + r) / 2;
	push(o);
	if (i < m)
		del(o+o+1,l,m,i);
	else
		del(o+o+2,m,r,i);
	pull(o);
}
void go(int o,int l,int r,int u,ll w)
{
	if (SZ(g[o])) {
		for (int i : g[o])
			if (e[i].S) {
				upd(0,0,n,e[i].F.F,e[i].F.S,w + e[i].S);
				e[i].S = 0;
			}
		g[o].clear();
	}
	if (r - l == 1)
		return;
	int m = (l + r) / 2;
	if (u < m)
		go(o+o+1,l,m,u,w);
	else
		go(o+o+2,m,r,u,w);
}
void pr(int o,int l,int r)
{
	if (r - l == 1) {
		ll w = t[o].p.F;
		PL<0,0>(w==inf?-1:w," \n"[r==n]);
		return;
	}
	int m = (l + r) / 2;
	pr(o+o+1,l,m);
	pr(o+o+2,m,r);
}
int main()
{
	int q,s;
	RD(n,q,s);
	--s;
	RP(i,q) {
		RI(t);
		int l, r;
		if (t == 1) {
			RIII(u,v,w);
			--u,--v;
			e[i] = {{v,v+1},w};
			l = u, r = u + 1;
		} else if (t == 2) {
			RIIII(u,vl,vr,w);
			--u,--vl;
			e[i] = {{vl,vr},w};
			l = u, r = u + 1;
		} else {
			RIIII(v,ul,ur,w);
			--v,--ul;
			e[i] = {{v,v+1},w};
			l = ul, r = ur;
		}
		add(0,0,n,l,r,i);
	}
	bld(0,0,n);
	upd(0,0,n,s,s+1,0);
	while (t[0].p.S != n && t[0].p.F != inf) {
		int u;
		ll w;
		tie(w,u) = t[0].p;
		del(0,0,n,u);
		go(0,0,n,u,w);
	}
	pr(0,0,n);
}
