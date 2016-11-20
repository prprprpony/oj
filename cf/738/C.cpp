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

const int maxn = 2.28e5, inf = 1e9 + 1;
int n, k, s, t;
int c[maxn], v[maxn], g[maxn];
bool ok(int cap)
{
	int x = 0;
	ll cur = 0;
	REP(i,0,k) {
		int d = g[i] - x;
		int y = min(cap - d, d);
		if (y < 0)
			return false;
		cur += y + 2LL * (d - y);
		x = g[i];
// y + z = d
// 2y + (d - y) <= cap
// d + y <= cap
// 0 <= y <= cap - d
	}
	return cur <= t;
}
int main()
{
	scanf("%d%d%d%d", &n, &k, &s, &t);
	REP(i,0,n)
		scanf("%d%d", c + i, v + i);
	REP(i,0,k)
		scanf("%d", g + i);
	g[k++] = s;
	sort(g, g + k);
	int low = 1, high = inf;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (ok(mid))
			high = mid - 1;
		else
			low = mid + 1;
	}
	int ans = inf;
	REP(i,0,n)
		if (v[i] >= low)
			ans = min(ans, c[i]);
	printf("%d\n", ans == inf ? -1 : ans);
}
