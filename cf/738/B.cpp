#include <bits/stdc++.h>
using namespace std;
// iteration
#define CONC(a,b) a ## b
#define CONC_M(a,b) CONC(a,b)
#define __REP(i,s,j,e,nxt) for (auto i = (s), j = (e); i != j; i nxt)
#define _REP(i,s,e,nxt) __REP(i,s,CONC_M(__e,__LINE__),e,nxt)
#define REP(i,s,e) _REP(i,s,e, ++)
#define PER(i,s,e) _REP(i,s,e, --)
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

// Good Luck && Have Fun !

const int maxn = 1024;
int g[maxn][maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i,0,n)
		REP(j,0,m)
			scanf("%d", &g[i][j]);
	int ans = 0;
	REP(i,0,n) {
		bool ok = false;
		REP(j,0,m) {
			if (ok && !g[i][j])
				++ans;
			ok = ok || g[i][j];
		}
	}
	REP(i,0,n) {
		bool ok = false;
		PER(j,m-1,-1) {
			if (ok && !g[i][j])
				++ans;
			ok = ok || g[i][j];
		}
	}
	REP(j,0,m) {
		bool ok = false;
		REP(i,0,n) {
			if (ok && !g[i][j])
				++ans;
			ok = ok || g[i][j];
		}
	}
	REP(j,0,m) {
		bool ok = false;
		PER(i,n-1,-1) {
			if (ok && !g[i][j])
				++ans;
			ok = ok || g[i][j];
		}
	}
	printf("%d\n", ans);
}
