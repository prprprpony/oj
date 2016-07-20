#include <cstdio>
using namespace std;
const int maxn = 20;
int n, k;
double p[maxn];
double dp[1 << maxn];
double ans[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	int pos = 0, zero = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lf", p + i);
		if (p[i] > 0.0)
			++pos; 
		else
			zero ^= (1 << i);
	}
	if (pos <= k) {
		for (int i = 0; i < n; ++i)
			ans[i] = p[i] > 0.0 ? 1.0 : 0.0;
		goto output;
	}
	dp[0] = 1.0;
	for (int S = 1, cnt = 1; S < (1 << n);
		S += (cnt == k ? S & -S : 1), cnt = __builtin_popcount(S)) {
		if (S & zero)
			continue;
		double tot = 0.0;
		for (int i = 0; i < n; ++i)
			if (!(S & (1 << i)))
				tot += p[i];
		for (int i = 0; i < n; ++i)
			if (S & (1 << i))
				dp[S] += p[i] / (tot + p[i]) * dp[S ^ (1 << i)];
		if (cnt == k)
			for (int i = 0; i < n; ++i)
				if (S & (1 << i)) 
					ans[i] += dp[S];
	}
output:
	for (int i = 0; i < n; ++i)
		printf("%.16f%c", ans[i], i != n - 1 ? ' ' : '\n');
}
