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
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* For it's time for you to fulfill your output */
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}
void PT(const double a) {printf("%.16f", a);}
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}

/* Good Luck && Have Fun ! */

const int maxn = 3.18e4;
int sz[maxn], sv[maxn], dep[maxn];
vi g[maxn];
int dfs(int d, int p, int u)
{
	sz[u] = 1;
	int low = dep[u] = d;
	for (int v : g[u]) if (v != p) {
		if (dep[v]) {
			cmin(low, dep[v]);
		} else {
			int lowv = dfs(d + 1, u, v);
			sz[u] += sz[v];
			cmin(low, lowv);
			if (lowv >= d)
				sv[u] += sz[v];
		}
	}
	return low;
}
int main()
{
	int n,m;
	RD(n,m);
	DO(m) {
		int u,v;
		RD(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	int k;
	RD(k);
	dfs(1,0,k);
	int x = 0;
	REP(i,1,n+1)
		if (i != k && sv[i] > sv[x])
			x = i;
	if (x)
		PL(x,sz[k]-sv[x]);
	else
		PL(0);
}
