#include <cstdio>
#include <algorithm>
#define MAXM 10005
#define MAXN 55
#define MAXP 55
using namespace std;

int dp[MAXN][MAXM];
int cost[MAXN][MAXP];
int power[MAXN][MAXP];

int main()
{
    int m, n, p;
    while (scanf("%d%d%d", &m, &n, &p) == 3) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < p; j++)
                scanf("%d%d", &cost[i][j], &power[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0 ; j <= m; j++) {
                dp[i][j] = (i > 0) ? dp[i-1][j] : 0;
                for (int k = 0; k < p; k++)
                    if (j >= cost[i][k])
                        dp[i][j] = max((i > 0 ? dp[i-1][j-cost[i][k]] : 0) + power[i][k], dp[i][j]);
            }
        printf("%d\n", dp[n-1][m]);
    }
    return 0;
}
