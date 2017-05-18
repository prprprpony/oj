#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i(a),_B(b);i<_B;++i)
#define RP(i,n) REP(i,0,n)
#define PB push_back
#define EB emplace_back
#define SZ(a) ((int)(a.size()))
#define ALL(a) a.begin(),a.end()
const int N = 106, M = 2e5 + 87, inf = 1e7;
struct Dinic
{
	int n,s,t;
	struct edge
	{
		int fr,to,rd;
		edge(){}
		edge(int a,int b,int c):fr(a),to(b),rd(c){}
	};
	vector<edge> E;
	vector<int> g[N];
	int lv[N], idx[N];
	void init(int _n,int _s,int _t)
	{
		n = _n;
		s = _s;
		t = _t;
		E.clear();
		RP(i,n)
			g[i].clear();
	}
	void addE(int u,int v,int c)
	{
		E.EB(u,v,c);
		E.EB(v,u,0);
		g[u].PB(SZ(E)-2);
		g[v].PB(SZ(E)-1);
	}
	bool bfs()
	{
		fill_n(lv,n,0);
		fill_n(idx,n,0);
		lv[s] = 1;
		queue<int> q;
		q.push(s);
		while (SZ(q)) {
			int u = q.front();
			q.pop();
			if (lv[u] == lv[t])
				break;
			for (int i : g[u]) if (E[i].rd) {
				int v = E[i].to;
				if (!lv[v]) {
					lv[v] = lv[u] + 1;
					q.push(v);
				}
			}
		}
		return lv[t];
	}
	int dfs(int u,int a)
	{
		if (u == t)
			return a;
		if (lv[u] >= lv[t] || !a)
			return 0;
		int ans = 0;
		for (int & i = idx[u]; i < SZ(g[u]); ++i) {
			int x = g[u][i];
			int v = E[x].to;
			if (lv[v] == lv[u] + 1) {
				int c = dfs(v,min(a, E[x].rd));
				a -= c;
				E[x].rd -= c;
				E[x^1].rd += c;
				ans += c;
				if (!a)
					break;
			}
		}
		return ans;
	}
	int mf()
	{
		int ans = 0;
		while (bfs())
			ans += dfs(s,inf);
		return ans;
	}
} flower;

bool sev[M];
vector< tuple<int,int,int> > a,a1;
int vl[N];
void pre()
{
	vector<int> p;
	sev[0] = sev[1] = 1;
	REP(i,2,M) {
		if (!sev[i])
			p.PB(i);
		for (auto j : p) {
			if (i * j >= M)
				break;
			sev[i * j] = 1;
			if (i % j == 0)
				break;
		}
	}
}
int solve(int ml)
{
	int m;
	for (m = 0; m < SZ(a) && get<0>(a[m]) <= ml; ++m);
	for (int i = 0; i < SZ(a1) && get<0>(a1[i]) <= ml; ++i)
		get<2>(a[0]) = max(get<2>(a[0]),get<2>(a1[i]));
	int s = m, t = m+1;
	flower.init(m+2,s,t);
	int ans = 0;
	RP(i,m) {
		ans += get<2>(a[i]);
		if (get<1>(a[i])&1) {
			flower.addE(s,i,get<2>(a[i]));
			RP(j,m)
				if (!sev[get<1>(a[j]) + get<1>(a[i])])
					flower.addE(i,j,inf);
		} else {
			flower.addE(i,t,get<2>(a[i]));
		}
	}
	ans -= flower.mf();
	get<2>(a[0]) = 0;
	return  ans;
}
int main()
{
	pre();
	int n,k;
	scanf("%d%d",&n,&k);
	a.EB(0,1,0);
	RP(i,n) {
		int p,c,l;
		scanf("%d%d%d",&p,&c,&l);
		if (c == 1)
			a1.EB(l,c,p);
		else
			a.EB(l,c,p);
		vl[i] = l;
	}
	sort(ALL(a));
	sort(ALL(a1));
	sort(vl,vl+n);
	int m = unique(vl,vl+n) - vl;
	int lo = 0, hi = m-1;
	while (lo <= hi) {
		int mi = (lo + hi) / 2;
		if (solve(vl[mi]) < k)
			lo = mi + 1;
		else
			hi = mi - 1;
	}
	printf("%d\n", lo == m ? -1 : vl[lo]);
}
