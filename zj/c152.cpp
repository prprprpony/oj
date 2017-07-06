#include<bits/stdc++.h>
using namespace std;
const int N = 10000 + 6, M = 100000 + 6;
const double inf = 1e15;
typedef long long ll;
typedef pair<int,int> pii;
tuple<int,int,int,int> e[M];
#define G(a,i) get<i>(a)
#define PB push_back
#define F first
#define S second
typedef pair<double,int> E;
vector<E> g[N];
double d[N];
pii pre[N];
void sp(int n,int s,int t)
{
	fill_n(d+1,n,inf);
	fill_n(pre+1,n,pii{0,0});
	d[s] = 0;
	priority_queue<E,vector<E>,greater<E>> pq;
	pq.push({0,s});
	while (pq.size()) {
		double w;
		int u;
		tie(w,u) = pq.top();
		pq.pop();
		if (w > d[u])
			continue;
		if (u == t)
			break;
		for (int i = 0; i < g[u].size(); ++i) {
			auto p = g[u][i];
			w = d[u] + p.F;
			int v = p.S;
			if (w < d[v]) {
				d[v] = w;
				pre[v] = {u,i};
				pq.push({w,v});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n,m,a,b;
		cin >> n >> m >> a >> b;
		for (int i = 0; i < m; ++i)
			cin >> G(e[i],0) >> G(e[i],1) >> G(e[i],2) >> G(e[i],3);
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		for (int i = 0; i < m; ++i) {
			double t = G(e[i],2)*1.0/G(e[i],3);
			g[G(e[i],0)].PB({t, G(e[i],1)});
			g[G(e[i],1)].PB({t, G(e[i],0)});
		}
		sp(n,a,b);
		vector<pii> p;
		for (int u = b; u != a; u = pre[u].F)
			p.PB(pre[u]);
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		for (int i = 0; i < m; ++i) {
			g[G(e[i],0)].PB({G(e[i],2), G(e[i],1)});
			g[G(e[i],1)].PB({G(e[i],2), G(e[i],0)});
		}
		sp(n,a,b);
		ll ans = 0;
		for (auto & x : p)
			ans += g[x.F][x.S].F;
		cout << (ll)d[b] << ' ' << ans << '\n';
	}
}
