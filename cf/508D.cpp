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

const int maxn = 2.28e5;
vi g[1 << 16];
int in[1 << 16];
int st[maxn], tp;
void dfs(int u)
{
	while (SZ(g[u])) {
		int v = BK(g[u]);
		DB(g[u]);
		dfs(v);
	}
	st[tp++] = u;
}
int main()
{
	int n;
	RD(n);
	DO(n) {
		char s[5];
		RD(s);
		int u = (s[0] | 0) << 8 | s[1];
		int v = (s[1] | 0) << 8 | s[2];
		g[u].PB(v);
		++in[v];
	}
	int v[2] = {-1,-1};
	RP(i,1 << 16)
		if (int d = in[i] - SZ(g[i])) {
			if (abs(d) != 1 || v[(d+1)/2] != -1) {
				PL("NO");
				return 0;
			}
			v[(d+1)/2] = i;
		}
	if ((v[0] == -1) != (v[1] == -1)) {
		PL("NO");
		return 0;
	}
	if (v[0] == -1)
		RP(i,1<<16)
			if (SZ(g[i]))
				v[0] = i;
	tp = 0;
	dfs(v[0]);
	if (tp != n + 1) {
		PL("NO");
		return 0;
	}
	PL("YES");
	putchar(v[0]>>8);
	while (tp)
		putchar(st[--tp] & ((1<<8)-1));
	PL();
}
