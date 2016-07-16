#include <cstdio>
#include <utility>
#include <algorithm>
#include <bitset>
#define C first
#define I second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 7e4 + 228;
pii a[maxn];
bitset<maxn> dp, tmp;
int dpc[maxn];
pii ans[maxn];
bool ok(int v, int n)
{
	dp[0] = 1;
	for (int i = 1; i <= n && !dp[v]; ++i) {
		tmp = dp;
		dp = (dp << a[i].C) | dp;
		tmp ^= dp;
		for (int j = tmp._Find_first(); j <= v; j = tmp._Find_next(j))
				dpc[j] = i;
	}
	return dp[v];
}
int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].C);
		a[i].I = i;
		sum += a[i].C;
	}
	sort(a + 1, a + 1 + n);
	if (s < a[n].C || s > sum || !ok(s - a[n].C, n - 1)) {
		puts("-1");
	} else {
		dpc[0] = 0;
		a[0].C = 1;
		int last = n;
		for (int j = s - a[n].C; j >= 0; last = dpc[j], j -= a[dpc[j]].C) {
			int i = dpc[j] + 1;
			ans[a[i].I] = {a[i].C, 0};
			for (; i < last; ++i)
				ans[a[i + 1].I] = {a[i + 1].C - a[i].C, a[i].I};
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d ", ans[i].C);
			if (ans[i].I)
				printf("1 %d\n", ans[i].I);
			else
				puts("0");
		}
	}
}
