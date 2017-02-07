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
const int M = 1e9+7,N=1.12e5;
vi g[N];
int d[N][2][2];
void exgcd(int a, ll & x, int b, ll & y, ll & g)
{
	if (b) {
		exgcd(b,y,a%b,x,g);
		y -= a/b*x;
	} else {
		x = 1; y = 0; g = a;
	}
}
int inv(int a)
{
	ll x,y,g;
	exgcd(M,x,a,y,g);
	assert(g == 1);
	return (x%M+M)%M;
}
int dp(int p, int u, int c, int o)
{
	int & now = d[u][c][o];
	if (now != -1)
		return now;
	if (o) {
		ll x = 1;
		for (auto v : g[u]) if (v != p)
			x = x * (((dp(u, v, c, 1) + dp(u, v, c^1, 1)) % M + dp(u,v,c,0)) % M) % M;
		now = (x - dp(p,u,c,0) + M) % M;
	} else {
		now = 1;
		for (auto v : g[u]) if (v != p)
			now = now * 1LL * dp(u,v,c^1,1) % M;
	}
	return now;
}
int main()
{
	int n;
	RD(n);
	DO(n-1) {
		int u,v;
		RD(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	memset(d, -1, sizeof(d));
	PL((dp(0,1,0,1) + dp(0,1,1,1)) % M);
}
