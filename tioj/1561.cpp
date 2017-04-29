#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define EB emplace_back
const int N = 106, inf = 0x3f3f3f3f;
vector<pii> g[N];
int d[N][2];
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m--) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u].EB(w,v);
			g[v].EB(w,u);
		}
		int s,t;
		scanf("%d%d",&s,&t);
		memset(d,0x3f,n*2*sizeof(int));
		d[s][0] = 0;
		set<pii> b;
		b.insert({0,s});
		while (b.size()) {
			int f,u,c,k;
			tie(f,u) = *b.begin();
			if (f == d[t][1])
				break;
			b.erase(b.begin());
			for (const auto & x : g[u]) {
				tie(c,k) = x;
				c += f;
				if (c < d[k][0]) {
					b.erase({d[k][1],k});
					d[k][1] = d[k][0];
					d[k][0] = c;
					b.insert({c,k});
				} else if (d[k][0] < c && c < d[k][1]) {
					b.erase({d[k][1],k});
					d[k][1] = c;
					b.insert({c,k});
				}
			}
		}
		if (d[t][1] == inf)
			puts("-1");
		else
			printf("%d\n",d[t][1]);
	}
}
