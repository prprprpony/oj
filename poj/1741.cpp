#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,s,e) for (int i = (s), __e = (e); i != __e; ++i)
#define rp(i,e) rep(i,0,e)
typedef pair<int,int> pii;
#define V first
#define D second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define CMAX(a, b) (a = max(a, b))
const int maxn = 10064;
vector<pii> g[maxn];
int sz[maxn];
int dep[maxn];
pii cent;
void dfs(int p, int u, int n) // calc sz && find centroid
{
	sz[u] = 1;
	int ms = 0;
	rp(i,SZ(g[u])) {
		int v = g[u][i].V;
		if (v == p) continue;
		dfs(u, v, n);
		CMAX(ms, sz[v]);
		sz[u] += sz[v];
	}
	CMAX(ms, n - sz[u]);
	if (ms < cent.D)
		cent = mp(u, ms);
}
void calc(int p, int u, int d, int & top) // calc sz && dep 
{
	sz[u] = 1;
	dep[top++] = d;
	rp(i,SZ(g[u])) {
		int v = g[u][i].V;
		int l = g[u][i].D;
		if (v == p) continue;
		calc(u, v, d + l, top);
		sz[u] += sz[v];
	}
}
int nump(int * a, int fi, int la, int k)
{
	a += fi;
	int n = la - fi;
	if (n < 2)
		return 0;
	sort(a, a + n);
	int i = 0, j = n - 1, ans = 0;
	for (; j >= 0; --j) {
		while (i < j && a[i] + a[j] <= k)
			++i;
		ans += i;
		if (i == j)
			break;
	}
	if (j >= 2) ans += j * (j - 1) / 2;
	return ans;
}
int solve(int u, int n, int k)
{
	if (n < 2)
		return 0;
	cent = mp(0,n+87);
	dfs(0, u, n);
	u = cent.V;
	int top = 0, ans = 0;
	rp(i,SZ(g[u])) {
		int fi = top;
		int v = g[u][i].V;
		int l = g[u][i].D;
		rp(j,SZ(g[v])) { // remove u 
			int w = g[v][j].V;
			if (w == u) {
				g[v][j] = g[v].back();
				g[v].pop_back();
				break;
			}
		}
		calc(u, v, l, top);
		ans -= nump(dep, fi, top, k);
	}
	dep[top++] = 0; // u
	ans += nump(dep, 0, top, k);
	rp(i,SZ(g[u])) {
		int v = g[u][i].V;
		ans += solve(v, sz[v], k);
	}
	return ans;
}
int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) == 2 && n) {
		rep(i,1,n+1) g[i].clear();
		rp(i,n-1) {
			int u, v, l;
			scanf("%d%d%d", &u, &v, &l);
			g[u].pb(mp(v,l));
			g[v].pb(mp(u,l));
		}
		printf("%d\n", solve(1, n, k));
	}
}
