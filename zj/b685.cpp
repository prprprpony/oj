#include<bits/stdc++.h>
using namespace std;
const int N = 1087, MOD = 1000007;
int c[N][N], fac[N], f[N][N];
void pre()
{
    for (int i = 0; i < N; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * 1ll * i % MOD;
    f[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i][1] = fac[i - 1];
        for (int j = 2; j <= i; ++j) {
            for (int k = 0; i - 1 - k >= j - 1; ++k) {
                f[i][j] = (f[i][j] + f[i - 1 - k][j - 1] * 1ll * c[i - 1][k] % MOD * fac[k]) % MOD;
            }
        }
    }
}
int n, m, a[N], p[N];
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
int bf()
{
    int pe[105];
    iota(pe + 1, pe + n + 1, 1);
    int ret = 0;
    do {
        iota(p, p + n + 1, 0);
        bool ok = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] && a[i] != pe[i]) {
                ok = 0;
                break;
            }
            int x = find(i), y = find(pe[i]);
            p[x] = y;
        }
        if (!ok)
            continue;
        int ct = 0;
        for (int i = 1; i <= n; ++i)
            ct += find(i) == i;
        ret += ct == m;
    } while (next_permutation(pe + 1, pe + n + 1));
    return ret % MOD;
}
int solve()
{
    iota(p, p + n + 1, 0);
    int tot = n, zero = 0;
    for (int i = 1; i <= n; ++i) {
        int j = a[i];
        if (j) {
            int x = find(i), y = find(j);
            if (x == y) {
                ++zero;
                continue;
            }
            p[y] = x;
            --tot;
        }
    }
    int one = tot - zero;
    int k = m - zero;
    if (k < 0)
        return 0;
    else
        return f[one][k];
}
int main()
{
    pre();
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        printf("%d\n", solve());
        //assert(solve() == bf());
    }
}
