#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn = 1e6 + 42;
typedef pair<int,int> pii;
#define L first
#define R second
int N, Q;
int w[maxn];
pii seg[maxn];
int BIT[maxn];
int cnt;
vector<int> g[maxn];
void dfs(int u) 
{
	seg[u].L = ++cnt;
	BIT[cnt] = w[u];
	for (auto v : g[u])
		dfs(v);
	seg[u].R = cnt;
}
void build()
{
	for (int i = 1; i <= N; ++i)
		BIT[i] += BIT[i - 1];
	for (int i = N; i >= 1; --i)
		BIT[i] -= BIT[i - (i & -i)];
}
void add(int i, int k)
{
	for (; i <= N; i += i & -i)
		BIT[i] += k;
}
int qry(int i)
{
	int ret = 0;
	for (; i; i ^= i & -i)
		ret += BIT[i];
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N - 1; ++i) {
		int a, b, m;
		cin >> a >> b >> m;
		g[a].pb(b);
		w[b] = m;
	}
	dfs(0);
	build();
	while (Q--) {
		int c;
		cin >> c;
		if (!c) {
			int D, M;
			cin >> D >> M;
			add(seg[D].L, M - w[D]);
			w[D] = M;
		} else {
			int D;
			cin >> D;
			cout << (qry(seg[D].R) - qry(seg[D].L)) * 2 << '\n';
		}
	}
}

