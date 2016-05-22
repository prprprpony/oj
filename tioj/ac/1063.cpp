#include <bits/stdc++.h>
#define MAXN 220
using namespace std;
int g[MAXN][MAXN];
int s[MAXN][MAXN];
int sum(int r, int c, int lr, int lc)
{
    return s[r+lr-1][c+lc-1] - s[r-1][c+lc-1] - s[r+lr-1][c-1] + s[r-1][c-1];
}
int main()
{
    int R, C;
    int ans = 0;
    cin >> R >> C;
    for (int r = 1; r <= R; r++)
        for (int c = 1; c <= C; c++)
            scanf("%d", g[r] + c);
    for (int c = 0; c <= C; c++)
        s[0][c] = 0;
    for (int r = 1; r <= R; r++)
        s[r][0] = 0;
    for (int r = 1; r <= R; r++)
        for (int c = 1; c <= C; c++)
            s[r][c] = s[r][c-1] - s[r-1][c-1] + s[r-1][c] + g[r][c];
    for (int wr = R; wr >= 1 && wr * C > ans; wr--)
        for (int wc = C; wc >= 1 && wc * wr > ans; wc--) {
            for (int sr = 1; sr <= R - wr + 1; sr++)
                for (int sc = 1; sc <= C - wc + 1; sc++) {
                    if (sum(sr, sc, wr, wc) == wr * wc) {
                        ans = wr * wc;
                        goto fin;
                    }
                }
            fin:
            ;
        }
    cout << ans << '\n';
}
