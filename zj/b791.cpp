#include <cstdio>
#define MAXN 25
using namespace std;
typedef long long ll;
ll dp[MAXN + 1];
int main()
{
    int n;
    dp[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        dp[i] = dp[i-1];
        if (i >= 2)
            dp[i] += dp[i-2];
        if (i >= 3)
            dp[i] += 4 * dp[i-3];
        if (i >= 4)
            dp[i] += 2 * dp[i-4];
    }
    while (scanf("%d", &n) == 1)
        printf("%lld\n", dp[n]);
    return 0;
}
