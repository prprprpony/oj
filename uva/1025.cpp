#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 52;
const int MAXT = 205;
const int INF = 2e8;
int N, T;
int t[MAXN];
bool have_train[MAXT][MAXN][2];
int dp[MAXT][MAXN];
int main()
{
	for (int i = 2; i < MAXN; ++i)
		dp[0][i] = INF;
	for (int kase = 1; scanf("%d", &N) == 1 && N > 0; ++kase) {
		scanf("%d", &T);
		for (int i = 1; i < N; ++i)
			scanf("%d", t + i);
		for (int i = 0; i <= T; ++i)
			memset(have_train[i], 0, (N + 1) * 2 * sizeof(bool));
		int M, d;
		scanf("%d", &M);
		while (M--) {
			scanf("%d", &d);
			for (int i = 1; i <= N && d <= T; d += t[i], ++i)
				have_train[d][i][0] = true;
		}
		scanf("%d", &M);
		while (M--) {
			scanf("%d", &d);
			for (int i = N; i > 0 && d <= T; --i, d += t[i])
				have_train[d][i][1] = true;
		}
		for (int i = 1; i <= T; ++i)
			for (int j = 1; j <= N; ++j) {
				dp[i][j] = dp[i-1][j] + 1;
				if (have_train[i][j][0] && j > 1)
					dp[i][j] = min(dp[i][j], dp[i - t[j - 1]][j - 1]);
				if (have_train[i][j][1] && j < N)
					dp[i][j] = min(dp[i][j], dp[i - t[j]][j + 1]);
			}
		printf("Case Number %d: ", kase);
		if (dp[T][N] < INF)
			printf("%d\n", dp[T][N]);
		else
			puts("impossible");
	}
}
