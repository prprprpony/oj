#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 1e9 + 7;
const int maxt = 101;
const int maxk = 1011;
const int tot = 4 * maxk * maxt;
const int s = tot / 2;
int dp[2][tot];
int sum[tot];
inline int add(int a, int b) {return (a += b) < M ? a : a - M;}
inline int sub(int a, int b) {return (a -= b) >= 0 ? a : a + M;}
int main()
{
	int a, b, k, t;
	scanf("%d%d%d%d", &a, &b, &k, &t);
	dp[0][s] = 1;
	for (int i = 1; i <= 2 * t; ++i) {
		int now = i & 1;
		sum[s - (i - 1) * k - 1] = 0;
		for (int j = s - (i - 1) * k; j <= s + (i - 1) * k; ++j)
			sum[j] = add(sum[j-1], dp[now^1][j]);
		for (int j = s - i * k; j <= s + i * k; ++j)
			dp[now][j] = sub(sum[min(s + (i-1) * k, j + k)], sum[max(s - (i-1) * k, j - k) - 1]);
	}
	int ans = 0;
	for (int i = s - (a - b) + 1; i <= s + 2 * k * t; ++i)
		ans = add(ans, dp[0][i]);
	printf("%d\n",ans);
}
