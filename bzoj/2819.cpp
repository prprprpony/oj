#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a), _B(b); i < _B; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1), _B(b); i >= _B; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
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

/* Good Luck && Have Fun ! */
const int N = 5e5 + 87, D = 19;
int a[N],lt[N],rt[N],dfn,f[N],pa[N][D],de[N], n;
vi g[N];
void dfs(int p,int u,int s)
{
	de[u] = de[p] + 1;
	pa[u][0] = p;
	REP(i,1,D)
		pa[u][i] = pa[pa[u][i-1]][i-1];
	f[lt[u] = ++dfn] = (s ^= a[u]);
	RP(i,SZ(g[u])) {
		int v = g[u][i];
		if (v != p) 
			dfs(u,v,s);
	}
	rt[u] = dfn + 1;
}
int lca(int u, int v)
{
	if (de[v] > de[u])
		swap(u,v);
	for (int x = de[u] - de[v], k = 0; x; x >>= 1, ++k)
		if (x & 1)
			u = pa[u][k];
	if (u == v)
		return u;
	PR(k,D)
		if (pa[u][k] != pa[v][k]) {
			u = pa[u][k];
			v = pa[v][k];
		}
	return pa[u][0];
}
void upd(int i,int v)
{
	for ( ; i <= n; i += i & -i)
		f[i] ^= v;		
}
int qry(int i)
{
	int ans = 0;
	for ( ; i; i ^= i & -i)
		ans ^= f[i];
	return ans;
}
int main()
{
	scanf("%d",&n);
	RP1(i,n) scanf("%d",a + i);
	DO(n-1) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(0,1,0);
	PR1(i,n)
		f[i] ^= f[i ^ (i & -i)];
	int q;
	scanf("%d",&q);
	DO(q) {
		char c;
		int u,v;
		scanf(" %c%d%d",&c,&u,&v);
		if (c == 'Q') {
			puts((qry(lt[u])^qry(lt[v])^a[lca(u,v)]) ? "Yes" : "No");
		} else {
			upd(lt[u],a[u]^v);
			upd(rt[u],a[u]^v);
			a[u] = v;
		}
	}
}
