#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
const int D = __lg(N) + 1;
int de[N], pa[N][D];
bool ty[N][D][2];
int lca(int u,int v)
{
	if (de[u] > de[v])
		swap(u, v);
	for (int d = de[v] - de[u], k = 0; d; k++, d>>=1)
		if (d&1)
			v = pa[v][k];
	if (v == u)
		return u;
	if (!de[u])
		return 0;
	for (int k = __lg(de[u]); k >= 0; --k)
		if ((1 << k) <= de[u] && pa[u][k] != pa[v][k]) {
			u = pa[u][k];
			v = pa[v][k]; 
		}
	return pa[v][0];
}
bool qry(int t,int p,int u)
{
	if (p == u)
		return 0;
	for (int d = de[u] - de[p], k = 0; d; k++, d>>=1)
		if (d&1) {
			if (!ty[u][k][t])
				return 0;
			u = pa[u][k];
		}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t, p;
		cin >> p >> t;
		if (p == -1)
			continue;
		de[i] = de[p] + 1;
		pa[i][0] = p;
		ty[i][0][t] = 1;
		for (int k = 1; (1<<k) <= de[i]; ++k) {
			pa[i][k] = pa[pa[i][k-1]][k-1];
			ty[i][k][t] = ty[i][k-1][t] && ty[pa[i][k-1]][k-1][t];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int t,u,v;
		cin >> t >> u >> v;
		int w = lca(u, v);
		if (!w) {
			cout << "NO\n";
			continue;
		}
		--t;
		if (t) {
			cout << ((w == u ? 1 : qry(0, w, u)) && qry(1, w, v) ?  "YES\n" : "NO\n");
		} else {
			cout << (w == u && qry(0, w, v) ?  "YES\n" : "NO\n");
		}
	}
}
