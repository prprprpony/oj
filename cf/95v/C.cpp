#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1); i >= (b); --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
#define DO(n) RP(__i,n)
template<class T>
void cmax(T & a, T b) {a = max(a, b);}
template<class T>
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
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define CLR(a) (a).clear()
#define BK(a) ((a).back())
#define FT(a) ((a).front())
#define DB(a) (a).pop_back()
#define DF(a) (a).pop_front()
#define PB push_back
#define EB emplace_back

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {}
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		for (char x : "([{") c += *s == x;
		for (char x : ")]}") c -= *s == x;
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
bool RD() {return 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<class T, class ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DR(T,...) T __VA_ARGS__; RD(__VA_ARGS__)
#define RI(...) DR(int,__VA_ARGS__)

/* For it's time for you to fulfill your output. */
void PT(const char & a) {putchar(a);}
void PT(char const * const & a) {fputs(a, stdout);}
void PT(const double & a) {printf("%.16f", a);}
void PT(const int & a) {printf("%d", a);}
void PT(const ll & a) {printf("%lld", a);}

/* The line will last forever! */
template<char s = ' ', char e = '\n'>
void PL() {if (e) PT(e);}
template<char s = ' ', char e = '\n', class T, class ... TT>
void PL(const T & a, const TT & ... b)
{PT(a); if (sizeof...(b) && s) PT(s); PL<s,e>(b...);}

/* Good Luck && Have Fun ! */
const int N = 1006, inf = 1e9 + 7;
vector<pii> g[N];
ll d[N], c[N];
vi gg[N];
void dijk(int u,int n)
{
	fill_n(d,n,inf);
	d[u] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0,u});
	while (SZ(pq)) {
		int w;
		tie(w,u) = pq.top();
		pq.pop();
		if (w > d[u])
			continue;
		for (const pii & p : g[u]) {
			w = d[u] + p.F;
			int v = p.S;
			if (w < d[v]) {
				d[v] = w;
				pq.push({w,v});
			}
		}
	}
}
int main()
{
	RI(n,m,x,y);
	--x, --y;
	DO(m) {
		RI(u,v,w);
		--u, --v;
		g[u].PB({w,v});
		g[v].PB({w,u});
	}
	RP(i,n) {
		dijk(i,n);
		int t;
		RD(t,c[i]);
		RP(j,n)
			if (d[j] <= t)
				gg[i].PB(j);
	}
	ll INF = 1e15;
	fill_n(d,n,INF);
	ll u = x;
	d[u] = 0;
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	pq.push({0,u});
	while (SZ(pq)) {
		ll w;
		tie(w,u) = pq.top();
		pq.pop();
		if (w > d[u])
			continue;
		if (u == y) {
			PL(w);
			return 0;
		}
		for (const int & v : gg[u]) {
			w = d[u] + c[u];
			if (w < d[v]) {
				d[v] = w;
				pq.push({w,v});
			}
		}
	}
	PL(-1);
}
