#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 26;
long long dp[maxn];
const int w[] = {0, 1, 1, 4, 2};
int main()
{
    dp[0] = 1;
    for (int i = 1; i < maxn; ++i)
        for (int j = 1; j <= i && j < sizeof(w) / sizeof(int); ++j)
            dp[i] += w[j] * dp[i-j];
    int N;
    while (scanf("%d", &N) == 1)
        printf("%lld\n", dp[N]);
}
