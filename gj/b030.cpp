#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
#define MAXM 1010
using namespace std;

int l[MAXN], s[MAXN];
int dp[MAXN][MAXM];

int main()
{
    int n, m;
    memset(dp, 0, sizeof(dp));

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &l[i], &s[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = ((j >= l[i]) ? max(dp[i-1][j], dp[i-1][j-l[i]] + s[i]) : dp[i-1][j]);

    printf("%d\n", dp[n][m]);

    return 0;
}
