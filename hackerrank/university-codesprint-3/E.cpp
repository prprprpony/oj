#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define F first
#define S second
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PB push_back
#define SZ(a) ((int)(a).size())
template<class T,class U>
bool cmax(T & a,const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a,const U & b) {return a > b ? a = b, 1 : 0;}
/* */
const int N = 1e5 + 87;
vector<int> g[N];
int n,c[N],dp[N],pa[N];
pii ans;
void dfs(int p,int u)
{
	pa[u] = p;
	dp[u] = c[u];
	for (int v : g[u]) if (v != p) {
		dfs(u,v);
		if (dp[v] > 0)
			dp[u] += dp[v];
	}
	cmax(ans, pii{dp[u],u});
}
void go(vi & va,int p,int u)
{
	va.PB(u);
	for (int v : g[u]) if (v != p && dp[v] > 0)
		go(va,u,v);
}
void solve(int & la, vi & va)
{
	ans = {-1e9,0};
	dfs(-1,0);
	if (ans.F > la) {
		la = ans.F;
		va.clear();
		go(va,pa[ans.S],ans.S);
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	RP(i,n) {cin >> c[i]; if (!c[i]) c[i] = -1;}
	RP(i,n-1) {
		int u,v;
		cin >> u >> v;
		--u,--v;
		g[u].PB(v);
		g[v].PB(u);
	}
	int la = -1e9;
	vi va;
	solve(la,va);
	RP(i,n) c[i] *= -1;
	solve(la,va);
	cout << la << '\n' << SZ(va) << '\n';
	RP(i,SZ(va))
		cout << va[i] + 1 << " \n"[i==SZ(va)-1];
}
