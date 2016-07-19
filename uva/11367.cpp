#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#define D first
#define V second
#define C first
#define P second
using namespace std;
const int maxn = 1024;
const int maxc = 125;
const int inf = 0x7f7f7f7f;
int p[maxn];
typedef pair<int,int> pii;
typedef pii node;
vector<pii> g[maxn];
int minc[maxn * maxc];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i);
	while (m--) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		g[u].emplace_back(d, v);
		g[v].emplace_back(d, u);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int c, s, e;
		scanf("%d%d%d", &c, &s, &e);
		priority_queue<node, vector<node>, greater<node> > pq;
		memset(minc, 0x7f, (c + 1) * n * sizeof(int));
		minc[s] = 0;
		pq.push({0, s});
		while (pq.size()) {
			node t = pq.top();
			pq.pop();
			pii u(t.P / n, t.P % n);
			if (t.C > minc[t.P])
				continue;
			else if (u.V == e)
				break;
			int nxt;
			if (u.D < c) {
				int cost = t.C + p[u.V];
				nxt = (u.D + 1) * n + u.V;
				if (minc[nxt] > cost) {
					minc[nxt] = cost;
					pq.push({cost, nxt});
				}
			}
			for (const pii & x : g[u.V])
				if (u.D >= x.D) {
					nxt = (u.D - x.D) * n + x.V;
					if (minc[nxt] > t.C) {
						minc[nxt] = t.C;
						pq.push({t.C, nxt});
					}
				}
		}
		if (minc[e] < inf)
			printf("%d\n", minc[e]);
		else
			puts("impossible");
	}
}
