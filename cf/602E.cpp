// FFT?
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 113;
const int maxm = 1e3 + 13;
double cnt[2][maxm * maxn];
int x[maxm];
double pre[maxm * maxn];
int main()
{
	int n, m, s = 0;
	scanf("%d%d", &n, &m);
	if (m == 1) {
		puts("1");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", x + i);
		s += x[i];
	}
	for (int i = 1; i <= m; ++i)
		if (i != x[1])
			cnt[0][i] = 1;
	int b = 0;
	for (int i = 2; i <= n; ++i) {
		pre[i-2] = 0.0;
		for (int j = i-1; j <= i * m; ++j)
			pre[j] = pre[j-1] + cnt[b][j];
		for (int j = i; j <= i * m; ++j) {
// cnt[b^1][j] = sigma 1 <= k <= m : cnt[b][j-k]
			int r = j - 1, l = max(i-2, j-m-1);
			cnt[b^1][j] = pre[r] - pre[l] - (r - l >= x[i] ? cnt[b][j-x[i]] : 0);
		}
		memset(cnt[b] + 1, 0, i * m * sizeof(cnt[0][0]));
		b ^= 1;
	}
	double sum = 0.0;
	for (int i = n; i < s; ++i)
		sum += cnt[b][i];
	printf("%.16f\n", 1 + exp(log(sum) - (n - 1) * log(m - 1.0)));
}
