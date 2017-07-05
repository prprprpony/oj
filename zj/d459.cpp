#include <cstdio>
#include <vector>
using namespace std;
const int N = 20000 + 87;
vector<int> g[N];
int sz[N];
void dfs(int p,int u)
{
	sz[u] = 1;
	for (int v : g[u]) if (v != p) {
		dfs(u,v);
		sz[u] += sz[v];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,1);
	for (int i = 1; i <= n; ++i)
		printf("%5d-%5d\n",i,sz[i]);
}
