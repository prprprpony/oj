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

const int maxn = 1 << 10;
bool G[maxn][maxn], is_cv[maxn], odd[maxn];
vi g[maxn], bcc[maxn];
int dep[maxn], bcc_cnt, bcc_id[maxn], st[maxn], tp;
int dfs(int d, int p, int u)
{
	int low = dep[u] = d;
	st[tp++] = u;
	for (int v : g[u]) if (v != p) {
		if (dep[v]) {
			cmin(low, dep[v]);
		} else {
			int lowv = dfs(d + 1, u, v);
			cmin(low, lowv);
			if (lowv >= d) {
				is_cv[u] = true;
				CLR(bcc[bcc_cnt]);
				int t;
				do {
					bcc_id[t = st[--tp]] = bcc_cnt;
					bcc[bcc_cnt].PB(t);
				} while (t != v);
				bcc_id[u] = bcc_cnt;
				bcc[bcc_cnt++].PB(u);
			}
		}
	}
	if (p == -1) is_cv[u] = SZ(g[u]) > 1;
	return low;
}
void init(int n)
{
	RP(i,n)
		fill_n(G[i], i, true);
	RP(i,n)
		CLR(g[i]);
	fill_n(dep, n, 0);
	fill_n(is_cv, n, false);
	fill_n(odd, n, false);
	tp = 0;
	bcc_cnt = 0;
}
bool is_bipartite(int d, int u)
{
	dep[u] = d;
	for (int v : g[u])
		if (bcc_id[v] == bcc_id[u])
			if (dep[v] == d || (!dep[v] && !is_bipartite(3 ^ d, v)))
				return false;
	return true;
}
bool is_bipartite(int i)
{
	for (int u : bcc[i]) {
		bcc_id[u] = i;
		dep[u] = 0;
	}
	return is_bipartite(1, BK(bcc[i]));
}
int main()
{
	int n,m;
	while (RD(n,m) && n) {
		init(n);
		while (m--) {
			int u, v;
			RD(u, v);
			--u, --v;
			if (u < v)
				swap(u, v);
			G[u][v] = false;
		}
		RP(i,n)
			RP(j,i)
			if (G[i][j])
				g[i].PB(j), g[j].PB(i);
		RP(i,n)
			if (!dep[i])
				dfs(1,-1,i);
		RP(i,bcc_cnt)
			if (!is_bipartite(i))
				for (int u : bcc[i])
					odd[u] = true;
		int ans = 0;
		RP(i,n)
			if (!odd[i])
				++ans;
		PL(ans);
	}
}
