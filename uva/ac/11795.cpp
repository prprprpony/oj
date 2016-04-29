#include <cstdio>
#include <cstring>
using namespace std;
int N;
int can_kill[1 << 17];
long long ways[1 << 17];

inline int lowbit(int x)
{
    return x & (-x);
}

long long dp(int defeated)
{
    if (ways[defeated])
        return ways[defeated];
    int left = defeated ^ 1;
    for (int i = lowbit(left); left; i = lowbit(left)) {
        if ((can_kill[defeated ^ i] & i) && dp(defeated ^ i) != -1)
            ways[defeated] += ways[defeated ^ i];
        left ^= i;
    }
    if (!ways[defeated])
        ways[defeated] = -1;
    return ways[defeated];
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d ", &N);
        memset(can_kill, 0, (1 << (N + 1)) * sizeof(int));
        memset(ways, 0, (1 << (N + 1)) * sizeof(long long));
        ways[1] = 1;

        for (int i = 0; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                char c;
                scanf(" %c", &c);
                can_kill[1 << i] |= ((int)(c - '0') << j);
            }
        }

        for (int i = 1; i < (1 << (N + 1)); ++i)
            can_kill[i] = can_kill[i ^ lowbit(i)] | can_kill[lowbit(i)];
        long long ans = dp((1 << (N + 1)) - 1);
        printf("Case %d: %lld\n", kase, ans < 0 ? 0 : ans);
    }
    return 0;
}
