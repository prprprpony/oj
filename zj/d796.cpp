#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 250 + 42;
int T[maxn][maxn];
long long BIT[maxn][maxn];
int N, Q;
inline int lowbit(int x) {return x & -x;}
void build()
{
    for (int r = 1; r <= N; ++r)
        for (int c = 1; c <= N; ++c)
            BIT[r][c] = BIT[r - 1][c] + BIT[r][c - 1] - BIT[r - 1][c - 1] + T[r][c];
    for (int r = N; r >= 1; --r)
        for (int c = N; c >= 1; --c)
            BIT[r][c] -= BIT[r ^ lowbit(r)][c] + BIT[r][c ^ lowbit(c)] - BIT[r ^ lowbit(r)][c ^ lowbit(c)];
}
void add(int r, int c, int v)
{
    for ( ; r <= N; r += lowbit(r))
        for (int col = c; col <= N; col += lowbit(col))
            BIT[r][col] += v;
}
long long sum(int r, int c)
{
    long long ret = 0;
    for ( ; r; r ^= lowbit(r))
        for (int col = c; col; col ^= lowbit(col))
            ret += BIT[r][col];
    return ret;
}
long long sum(int x1, int y1, int x2, int y2)
{
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}
int main()
{
    scanf("%d%d", &N, &Q);
    for (int r = 1; r <= N; ++r)
        for (int c = 1; c <= N; ++c)
            scanf("%d", &T[r][c]);
    build();
    while (Q--) {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd) {
        case 1:
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);
            printf("%lld\n", sum(x1, y1, x2, y2));
            break;
        case 2:
            int r, c, v;
            scanf("%d%d%d", &r, &c, &v);
            add(r, c, v - T[r][c]);
            T[r][c] = v;
            break;
        }
    }
}

