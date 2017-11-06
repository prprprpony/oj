#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())
typedef pair<int,int> pii;
#define F first
#define S second
/*>_<*/
const int N = 3e5 + 87;
vector<int> g[N], t[N];
int de[N],rp[N],pa[N*2], up[N], lca[N];
pii q[N];
int find(int x,int * p = pa) {return p[x] == x ? x : p[x] = find(p[x],p);}
void meld(int a,int b,int *p=pa)
{
	a = find(a,p);
	b = find(b,p);
	p[a] = b;
}
void dfs(int p,int u)
{
	rp[u] = p;
	de[u] = de[p] + 1;
	for (int v : g[u])
		if (v != p) {
			dfs(u,v);
			meld(v,u);
		}
	for (int i : t[u])
		if (!lca[i])
			lca[i] = -1;
		else
			lca[i] = find(q[i].F^q[i].S^u);
}
void go(int v,int w)
{
	v = find(v,up);
	while (de[v] > de[w] + 1) {
		meld(v<<1,rp[v]<<1);
		meld(v<<1|1,rp[v]<<1|1);
		meld(v,rp[v],up);
		v = find(v,up);
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].PB(v);
		g[v].PB(u);
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		t[u].PB(i);
		t[v].PB(i);
		q[i] = {u,v};
	}
	for (int i = 1; i <= n; ++i)
		pa[i] = i;
	dfs(0,1);
	for (int i = 2<<1; i <= (n<<1|1); ++i)
		pa[i] = i;
	for (int i = 2; i <= n; ++i)
		up[i] = i;
	for (int i = 0; i < m; ++i) {
		int u, v;
		int w = lca[i];
		tie(u,v) = q[i];
		if (v == w)
			swap(u,v);
		if (u == w) {
			go(v,w);
		} else {
			go(v,w);
			go(u,w);
			meld(v<<1,u<<1|1);
			meld(v<<1|1,u<<1);
		}
	}
	vector<int> v;
	for (int i = 2; i <= n; ++i) {
		int a = find(i<<1), b = find(i<<1|1);
		if (a == b) {
			cout << "0\n";
			return 0;
		}
		v.PB(a);
		v.PB(b);
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)),end(v));
	int k = SZ(v)/2;
	int ans = 1;
	const int M = 1e9 + 7;
	while (k--)
		ans = (ans + ans) % M;
	cout << ans << '\n';
}
