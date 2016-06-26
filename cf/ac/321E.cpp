#include <cstdio>
#include <algorithm>
#define MAXN 4242
#define INF (int)1e9 + 689
#define MAXK 808
using namespace std;
char u[MAXN][2 * MAXN];
int s[MAXN][MAXN];
int dp[MAXK][MAXN];
int cost[MAXN][MAXN];

void calc(int i, int l, int r, int optl, int optr) {
    int m = (l + r) / 2;
    int optm;
    dp[i][m] = INF;
    for (int q = optl; q <= optr && q < m; q++) {
        if (dp[i-1][q] + cost[q+1][m] < dp[i][m]) {
            dp[i][m] = dp[i-1][q] + cost[q+1][m];
            optm = q;
        }
    }
    if (l < m)
        calc(i, l, m-1, optl, optm);
    if (r > m)
        calc(i, m+1, r, optm, optr);
}

int main()
{
    int n, k;
    scanf("%d%d ", &n, &k);
    for (int i = 1; i <= n; i++) {
        fgets(u[i], sizeof(u[i]), stdin);
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i][j-1] + u[i][2 * (j - 1)] - '0';
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            cost[i][j] = cost[i][j-1] + s[j][j-1] - s[j][i-1];
    for (int q = 1; q <= n - (k - 1); q++)
        dp[1][q] = cost[1][q];
// O(k * nlgn)
    for (int i = 2; i <= k; i++)
        calc(i, i, n - (k - i), i - 1, n - (k - i + 1));
/* naive way: O(k * n^2)
    for (int i = 2; i <= k; i++) {
        for (int q = i; q <= n - (k - i); q++) {
            dp[i][q] = INF;
            for (int p = 1; q - p >= i - 1; p++)
                dp[i][q] = min(dp[i][q], dp[i-1][q-p] + cost[q-p+1][q]);
        }
    }
*/
    printf("%d\n", dp[k][n]);
    return 0;
}
