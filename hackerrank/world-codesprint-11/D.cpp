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
const int N = 5e4 + 514, Q = 1e5 + 87;
vi g[N];
pii w[Q];
bool ons[N], vis[N];
int q,low[N],dfn,st[N],tp,co[N],sc;
set<int> dag[N];
bitset<N> tc[N];
void dfs(int u)
{
	int d = low[u] = ++dfn;
	ons[u] = 1;
	st[tp++] = u;
	for (int v : g[u]) {
		if (!low[v])
			dfs(v);
		if (ons[v])
			cmin(low[u], low[v]);
	}
	if (low[u] == d) {
		int v;
		int c = ++sc;
		do {
			v = st[--tp];
			ons[v] = 0;
			co[v] = c;
		} while (v != u);
	}
}
void flcl(int u)
{
	if (vis[u])
		return;
	vis[u] = 1;
	tc[u][u] = 1;
	for (int v : dag[u]) {
		flcl(v);
		tc[u] |= tc[v];
	}
}
int main()
{
	RII(n,m);
	DO(m) {RII(u,v); g[u].PB(v);}
	RD(m);
	DO(m) {
		RIII(t,x,y);
		if (t == 1) {
			++n;
			if (y)
				g[n].PB(x);
			else
				g[x].PB(n);
		} else {
			w[q++] = {x,y};
		}
	}
	RP1(i,n)
		if (!low[i])
			dfs(i);
	RP1(i,n)
		for (int j : g[i])
			if (co[i] != co[j])
				dag[co[i]].insert(co[j]);
	RP1(i,sc)
		flcl(i);
	RP(i,q)
		PL(tc[co[w[i].F]][co[w[i].S]] ? "Yes" : "No");
}
