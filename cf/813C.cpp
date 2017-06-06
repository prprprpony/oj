#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87;
vector<int> g[N];
int d[N],p[N],l[N];
void dfs(int pa,int u)
{
	p[u] = pa;
	l[u] = d[u] = d[pa] + 1;
	for (int v : g[u]) if (v != pa) {
		dfs(u,v);
		l[u] = max(l[u], l[v]);
	}
}
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for (int i = 0; i < n - 1; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	d[0] = -1;
	dfs(0,1);
	int ans = d[x];
	for (int u = x; d[x] - d[u] < d[u]; u = p[u])
		ans = max(ans, l[u] * 2);
	printf("%d\n",ans);
}
