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
const int N = 1.12e5;
vi g[N], q[N], q0[N];
int c[N], p[N], sz[N];
pii mp;
int find(int x) {return x == p[x] ? x : (p[x] = find(p[x]));}
void meld(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[a] > sz[b])
		swap(a,b);
	p[a] = b;
	sz[b] += sz[a];
}
void dfs(int p, int u)
{
	if (p != -1 && c[p] == c[u])
		meld(p, u);
	for (auto v : g[u]) if (v != p)
		dfs(u, v);
}
void dfs2(int p, int u)
{
	if (p != -1 && find(p) != find(u)) {
		int x = find(p), y = find(u);
		q[x].PB(y);
		q[y].PB(x);
		q0[x].PB(p);
		q0[y].PB(u);
	}
	for (auto v : g[u]) if (v != p)
		dfs2(u, v);
}
void dfs3(int d, int p, int u)
{
	cmax(mp, {d,u});
	for (auto v : q[u]) if (v != p)
		dfs3(d+1,u,v);
}
int main()
{
	int n;
	RD(n);
	DO(n-1) {
		int u,v;
		RD(u,v);
		--u, --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	RP(i,n) RD(c[i]);
	RP(i,n) {p[i] = i; sz[i] = 1;}
	dfs(-1,0);
	dfs2(-1,0);
	mp = {-1,-1};
	dfs3(0,-1,find(0));
	dfs3(0,-1,mp.S);
	if (mp.F > 2) {
		PL("NO");
	} else if (mp.F == 0) {
		PL("YES");
		PL(1);
	} else if (mp.F == 1) {
		int x = q0[mp.S][0];
		PL("YES");
		PL(x + 1);
	} else {
		int x = q[mp.S][0];
		REP(i,1,SZ(q0[x]))
			if (q0[x][i] != q0[x][i-1]) {
				PL("NO");
				return 0;
			}
		PL("YES");
		PL(q0[x][0]+1);
	}
}
