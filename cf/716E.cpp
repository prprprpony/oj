#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
int M,ti;
vector<pii> g[N];
int sz[N];
pii ct;
map<int,int> mp, cm[N];
void exgcd(ll a,ll&x,ll b,ll&y,ll&g)
{
	if (b) {
		exgcd(b,y,a%b,x,g);
		y -= a/b*x;
	} else {
		x = 1;
		y = 0;
		g = a;
	}
}
int inv(int a)
{
	ll x,y,g;
	exgcd(a,x,M,y,g);
	assert(g==1);
	return (x%M+M)%M;
}
int add(int a,int b) {return (a+=b) < M ? a : a-M;}
int mul(int a,int b) {return a*1LL*b%M;}
void fct(int p,int u,int n)
{
	int c = 0;
	sz[u] = 1;
	for (auto v : g[u]) if (v.F != p) {
		fct(u,v.F,n);
		c = max(c, sz[v.F]);
		sz[u] += sz[v.F];
	}
	c = max(c, n - sz[u]);
	ct = min(ct, {c,u});
}
void dfs(int p,int u,int d,int s,int k = 0,bool rt = 1)
{
	mp[s]++;
	if (!rt)
		cm[k][s]++;
	for (auto v : g[u])
		if (v.F != p) {
			if (rt)
				dfs(u,v.F,mul(d,10),add(mul(v.S,d),s),k++,0);
			else
				dfs(u,v.F,mul(d,10),add(mul(v.S,d),s),k,0);
		}
}
ll dfs2(int p,int u,int d,int di,int s,int si,int k=0,bool rt=1)
{
	int rv = mul(mul(si,M-1),di);
	ll ans = mp[rv];
	if (!rt)
		ans -= cm[k][rv];
	else
		--ans;
	for (auto v : g[u])
		if (v.F != p) {
			if (rt)
				ans += dfs2(u,v.F,mul(d,10),mul(di,ti),add(mul(v.S,d),s), add(mul(si,10),v.S),k++,0);
			else
				ans += dfs2(u,v.F,mul(d,10),mul(di,ti),add(mul(v.S,d),s), add(mul(si,10),v.S),k,0);
		}
	return ans;
}
ll solve(int u,int n)
{
	ct = {n,u};
	fct(-1,u,n);
	u = ct.S;
	mp.clear();
	for (int i = 0; i < n; ++i)
		cm[i].clear();
	dfs(-1,u,1,0);
	ll ans = dfs2(-1,u,1,1,0,0);
	for (auto v : g[u]) {
		for (auto & w : g[v.F]) 
			if (w.F == u) {
				w = g[v.F].back();
				g[v.F].pop_back();
				break;
			}
		ans += solve(v.F,sz[v.F] < sz[u] ? sz[v.F] : n - sz[u]);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> M;
	ti = inv(10);
	for (int i = 0; i < n-1; ++i) {
		int u,v,w;
		cin >> u >> v >> w;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	cout << solve(0,n) << '\n';
}
