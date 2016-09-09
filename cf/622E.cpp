#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define D first
#define U second
#define P first
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
const int maxn = 5.4e5;
vector<int> g[maxn];
int solve(int u)
{
	queue<pip> q;
	q.push({1, pii(1,u)});
	int cntl = 0;
	int lastd = 0;
	while (q.size()) {
		int d = q.front().D;
		int p = q.front().U.P;
		int v = q.front().U.U;
		q.pop();
		if (g[v].size() > 1) {
			for (int i : g[v]) if (i != p)
				q.push({d+1, pii(v, i)});
		} else {
			++cntl;
			if (d > lastd) {
				int emp = d - lastd;
				cntl -= min(cntl, emp);
				lastd = d;
			}
		}
	}
	return lastd + cntl;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans = 1;
	for (auto c : g[1])
		ans = max(ans, solve(c));
	printf("%d\n", ans);
}
