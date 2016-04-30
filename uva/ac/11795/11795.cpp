#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 16;
int N;
int can_kill[1 << MAXN];
long long ways[1 << MAXN];

inline int getmask()
{
    int mask = 0;
    for (int i = 0; i < N; ++i)
         mask |= ((getchar() - '0') << i);
    getchar();
    return mask;
}

inline int lowbit(int x)
{
    return x & (-x);
}

long long dp(int defeated)
{
    if (ways[defeated] != -1)
        return ways[defeated];
    ways[defeated] = 0;
    for (int left = defeated, i = lowbit(left); left; left ^= i, i = lowbit(left))
        if ((can_kill[defeated ^ i] & i) && dp(defeated ^ i))
            ways[defeated] += ways[defeated ^ i];
    return ways[defeated];
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d ", &N);
        memset(can_kill, 0, (1 << N) * sizeof(int));
        memset(ways, -1, (1 << N) * sizeof(long long));
        ways[0] = 1;
        can_kill[0] = getmask();

        for (int i = 0; i < N; ++i)
            can_kill[1 << i] = getmask();

        for (int i = 1; i < (1 << N); ++i)
            can_kill[i] = can_kill[i ^ lowbit(i)] | can_kill[lowbit(i)];
        printf("Case %d: %lld\n", kase, dp((1 << N) - 1));
    }
    return 0;
}
