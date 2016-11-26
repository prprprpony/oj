#include <bits/stdc++.h>
using namespace std;
// iteration
#define CONC(a,b) a ## b
#define CONC_M(a,b) CONC(a,b)
#define __REP(i,s,j,e,nxt) for (auto i = (s), j = (e); i != j; i nxt)
#define _REP(i,s,e,nxt) __REP(i,s,CONC_M(__e,__LINE__),e,nxt)
#define REP(i,s,e) _REP(i,s,e, ++)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) _REP(i,s,e, --)
#define PR(i,n) PER(i,n-1,-1)
#define REP_B(i,e) _REP(i,1,e, <<= 1)
#define DO(n) REP(CONC_M(__i,__LINE__),0,n)

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
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Good Luck && Have Fun ! */

const int maxn = 3.18e5;
vector<pii> g[maxn];
int dep[maxn];
int st[maxn];
int top;
int cnt;
int vt[maxn], pa[maxn];
bool hv[maxn], tp[maxn];
int dfs(int d, int p, int u)
{
	st[top++] = u;
	int lowu = dep[u] = d;
	for (auto v : g[u]) if (v.F != p) {
		if (!dep[v.F]) {
			int lowv = dfs(d + 1, u, v.F);
			lowu = min(lowu, lowv);
			if (lowv > d) {
				++cnt;
				for (;;) {
					int x = st[--top];
					vt[x] = cnt;
					if (!hv[cnt])
						for (auto y : g[x])
							if (vt[y.F] == cnt && y.S) {
								hv[cnt] = true;
								break;
							}
					if (x == v.F)
						break;
				}
				tp[cnt] = v.S;
				pa[cnt] = u;
			}
		} else {
			lowu = min(lowu, dep[v.F]);
		}
	}
	if (d == 1) {
		++cnt;
		while (top--) {
			int x = st[top];
			vt[x] = cnt;
			for (auto y : g[x])
				if (vt[y.F] == cnt)
					hv[cnt] = hv[cnt] || y.S;
		}
		tp[cnt] = false;
		pa[cnt] = 0;
	}
	return lowu;
}
int main()
{
	int n, m, a, b;
	RD(n, m);
	DO(m) {
		int u, v, z;
		RD(u, v, z);
		g[u].EB(v, z);
		g[v].EB(u, z);
	}
	RD(a, b);
	top = cnt = 0;
	dfs(1,0,a);
	for (b = vt[b]; b; b = vt[pa[b]])
		if (hv[b] || tp[b]) {
			puts("YES");
			return 0;
		}
	puts("NO");
}
