#include <cstdio>
#include <cstdlib>
const int maxn = 11;
int C[maxn][maxn];
void build_C()
{
    for (int n = 0; n < maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int m = 1; m < n; ++m)
            C[n][m] = C[n-1][m] + C[n-1][m-1];
#ifdef PP
for (int m = 0; m <= n; ++m)
    printf("C[%d][%d] = %d\n", n, m, C[n][m]);
#endif
    }
}

int main()
{
    int c;
    int g = 0;
    while ((c = getchar()) != '\n')
        g += (c == '+' ? 1 : -1);
    int p = 0;
    int r = 0;
    while ((c = getchar()) != '\n') {
        if (c == '?') {
            ++r;
        } else {
            p += (c == '+' ? 1 : -1);
        }
    }
/*
r   pos
0    1
1   101
2  10201
3 1030301   
*/
    build_C();
    double ans = 0.0;
    if (abs(g - p) <= r && !((abs(g - p) ^ r) & 1))
        ans = C[r][(g - (p - r)) / 2] / (double)(1 << r);
    printf("%.15f\n", ans);
}
