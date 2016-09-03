#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2.28e3;
int c[maxn];
bool dp[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    dp[0] = true;
    while (T--) {
        int N, K;
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; ++i)
            scanf("%d", c + i);
        memset(dp + 1, 0, K * sizeof(bool));
        int ans = 0;
        for (int i = 1; i <= K; ++i)
            for (int j = 0; j < N && !dp[i]; ++j)
                if (c[j] <= i && dp[i - c[j]]) {
                    dp[i] = true;
                    ans = i;
                }
        printf("%d\n", ans);
    }
}
