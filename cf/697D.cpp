#include <bits/stdc++.h>
using namespace std;
// daily life
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
#define DB(a) a.pop_back()
#define DF(a) a.pop_front()
#define PB push_back
#define EB emplace_back

// input
bool RD(void) {return true;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Good Luck && Have Fun ! */

const int maxn = 1.12e5;
vector<int> g[maxn];
int sz[maxn];
double e[maxn];
void getsz(int p, int u)
{
	sz[u] = 1;
	for (int v : g[u]) if (v != p) {
		getsz(u, v);
		sz[u] += sz[v];
	}
}
void calc(int p, int u)
{
	for (int v : g[u]) if (v != p) {
		e[v] = e[u] + (sz[u] - 1 - sz[v]) / 2.0 + 1.0;
		calc(u, v);
	}
}
int main()
{
	int n;
	RD(n);
	REP(i,2,n+1) {
		int p;
		RD(p);
		g[i].PB(p);
		g[p].PB(i);
	}
	getsz(0, 1);
	e[1] = 1.0;
	calc(0, 1);
	REP(i,1,n+1)
		printf("%.15lf%c", e[i], " \n"[i == n]);
}
