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
const int N = 2e5 + 87, inf = 1e7;
struct lift
{
	int n,d[N],p[N][__lg(N)+1];
	ll w[N];
	void bld(int * pa, ll * wt,int _n) {
		n = _n;
		d[n] = 0;
		p[n][0] = 0;
		w[n] = 0;
		PR1(i,n-1) {
			d[i] = d[pa[i]] + 1;
			w[i] = w[pa[i]] + wt[i];
			p[i][0] = pa[i];
			for (int k = 1; (1<<k) <= d[i]; ++k)
				p[i][k] = p[p[i][k-1]][k-1];
		}
	}
	pll qry(int x,int y)
	{
		if (x == y)
			return {x,0};
		int u = x;
		for (int k = __lg(d[x]); k >= 0; --k)
			if ((1<<k) <= d[u] && p[u][k] <= y)
				u = p[u][k];
		return {u,w[x] - w[u]};
	}
} t1,t2;
ll w[N],m[N],g[N],p[N];
int pa[N],pb[N];
int main()
{
	RII(n,q);
	RP1(i,n-1) RD(w[i]);
	RP1(i,n) RD(g[i],p[i]);
	p[n] = 0;
	PR1(i,n-1) {
		ll s = g[i] - w[i];
		int & u = pa[i];
		u = i + 1;
		while (u != n && s >= 0) {
			p[i] = min(p[i],p[u]);
			s -= w[u];
			u = pa[u];
		}
		w[i] = max(-s, 0LL);
	}
	PR1(i,n-1) {
		int & u = pb[i];
		u = pa[i];
		m[i] = w[i];
		while (p[i] <= p[u]) {
			m[i] += m[u];
			u = pb[u];
		}
	}
	RP1(i,n-1) m[i] *= p[i];
	t1.bld(pa,w,n);
	t2.bld(pb,m,n);
	DO(q) {
		RII(x,y);
		auto e = t2.qry(x,y);
		auto f = t1.qry(e.F,y);
		PL(e.S + p[e.F] * f.S);
	}
}
