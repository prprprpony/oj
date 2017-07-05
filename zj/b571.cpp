#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 504, inf = 0x3f3f3f3f, dr[] = {0,1,-1,0}, dc[] = {-1,0,0,1};
char g[N][N];
int d[N][N][3];
int main()
{
	int n,m;
	pii s;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%s",g[i]);
		for (int j = 0; j < m; ++j)
			if (g[i][j] == 'X')
				s = {i,j};
	}
	for (int i = 0; i < n; ++i)
		memset(d[i],0x3f,m*3*sizeof(int));
	d[s.F][s.S][0] = 0;
	vector<pii> q[2];
	q[0].push_back(s);
	for (int w = 1, b = 0; q[b].size(); ++w, b ^= 1) {
		int k = (w-1)%3;
		int v = w%3;
		for (const pii & p : q[b]) {
			for (int i = 0; i < 4; ++i) {
				pii t(p.F + dr[i], p.S + dc[i]);
				if (0 <= t.F && t.F < n && 0 <= t.S && t.S < m) {
					char c = g[t.F][t.S];
					if (c == '#' || ('A' <= c && c <= 'C' && c - 'A' == v))
						continue;
					if (w >= d[t.F][t.S][v])
						continue;
					if (c == 'Y') {
						printf("%d\n", w);
						return 0;
					}
					d[t.F][t.S][v] = w;
					q[b^1].push_back(t);
				}
			}
		}
		q[b].clear();
	}
	puts("-1");
}
