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

const int maxn = 2025;
int n, m, k;
typedef pair<int,pii> node;
vector<node> g[maxn];
int la[maxn];
bool off[maxn];
vector<pii> seg[maxn];
struct ask
{
	int r[2], c[2];
} a[maxn];
ll ans[maxn];

ll B[maxn][maxn];
void add(int r, int c, ll v)
{
	if (!r || !c)
		return;
	for (int i = r; i <= n; i += i&-i)
		for (int j = c; j <= m; j += j&-j)
			B[i][j] += v;
}
ll qry(int r, int c)
{
	ll ret = 0;
	for (int i = r; i; i ^= i&-i)
		for (int j = c; j; j ^= j&-j)
			ret += B[i][j];
	return ret;
}
ll qry(int r0, int c0, int r1, int c1)
{
	return qry(r1, c1) - qry(r1,c0-1) - qry(r0-1,c1) + qry(r0-1,c0-1);
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	REP(i,0,k) {
		int len;
		scanf("%d", &len);
		while (len--) {
			int r, c, w;
			scanf("%d%d%d", &r, &c, &w);
			g[i].EB(w, pii{r, c});
		}
	}
	int q, p = 0;
	char cmd[42];
	scanf("%d", &q);
	while (q--) {
		scanf("%s", cmd);
		if (cmd[0] == 'S') {
			int x;
			scanf("%d", &x);
			--x;
			if (!off[x])
				seg[x].EB(la[x], p);
			else
				la[x] = p;
			off[x] = !off[x];
		} else {
			scanf("%d%d%d%d", a[p].r, a[p].c, a[p].r + 1, a[p].c + 1);
			++p;
		}
	}
	REP(x,0,k)
		if (!off[x])
			seg[x].EB(la[x], p);
	REP(i,0,k) {
		for (auto v : g[i])
			add(v.S.F, v.S.S, v.F);
		for (auto v : seg[i])
			REP(j,v.F,v.S)
				ans[j] += qry(a[j].r[0], a[j].c[0], a[j].r[1], a[j].c[1]);
		for (auto v : g[i])
			add(v.S.F, v.S.S, -v.F);
	}
	REP(i,0,p)
		printf("%lld\n", ans[i]);
}
