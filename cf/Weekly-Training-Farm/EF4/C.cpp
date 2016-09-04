#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 2e5 + 426;
bool vis[maxn];
vector<int> v[maxn];
int cnt[3 * maxn];
int num;
long long s;
void dfs(int i, int d, int x, int p)
{
	if (d) {
		if (vis[x]) {
			--cnt[p];
			s += ((d & 1) ?  1: -1) * cnt[p];
		} else {
			s += ((d & 1) ?  -1: 1) * cnt[p];
			++cnt[p];
		}
	}
	for (; i < v[x].size(); ++i)
		dfs(i + 1, d + 1, x, v[x][i] * p);
}
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (!(a & 1)) {
			v[i] = {2};
			while (!(a & 1))
				a >>= 1;
		}
		for (int j = 3; j * j <= a; j += 2)
			if (a % j == 0) {
				v[i].push_back(j);
				while (a % j == 0)
					a /= j;
			}
		if (a != 1)
			v[i].push_back(a);
	}
	while (q--) {
		int x;
		scanf("%d", &x);
		--x;
		if (vis[x]) {
			--num;
			s -= num;
		} else {
			s += num;
			++num;
		}
		dfs(0, 0, x, 1);
		vis[x] = !vis[x];
		printf("%lld\n", s);
	}
}
