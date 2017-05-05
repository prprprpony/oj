#include<bits/stdc++.h>
using namespace std;
const int N = 205;
vector<int> g[N];
bool vy[N];
int my[N];
int n,m;
bool dfs(int x)
{
	for (int y : g[x])
		if (!vy[y]) {
			vy[y] = 1;
			if (my[y] == -1 || dfs(my[y])) {
				my[y] = x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	while (scanf("%d%d",&n,&m) == 2) {
		for (int r = 0; r < n; ++r) {
			g[r].clear();
			for (int c = 0; c < m; ++c) {
				int v;
				while (!isdigit(v = getchar()));
				if (v == '0')
					g[r].push_back(c);
			}
		}
		int mat = 0;
		memset(my,-1,m*sizeof(int));
		for (int x = 0; x < n; ++x) {
			memset(vy,0,m*sizeof(bool));
			if (dfs(x))
				++mat;
		}
		static int kase = 0;
		printf("Case %d: %d\n", ++kase, (n+m-mat)<<1);
	}
}
