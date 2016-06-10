#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10;
bool g[maxn][maxn][4];
int d[maxn][maxn][4];
int ans[maxn];
/*
RULD
0123
*/

int main()
{
    int n, m;
    int kase = 0;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++i) {
            memset(g[i] + 1, 0, n * 4 * sizeof(bool));
            memset(d[i] + 1, 0, n * 4 * sizeof(int));
        }
        memset(ans + 1, 0, n * sizeof(int));

        while (m--) {
            char c;
            int i, j;
            scanf(" %c%d%d", &c, &i, &j);
            if (c == 'H')
                g[i][j][0] = g[i][j+1][2] = true;
            else if (c == 'V')
                g[j][i][3] = g[j+1][i][1] = true;
        }

        for (int r = 1; r <= n; ++r) {
            for (int c = n - 1; c >= 1; --c)
                d[r][c][0] = g[r][c][0] ? 1 + d[r][c+1][0] : 0;
            for (int c = 2; c <= n; ++c)
                d[r][c][2] = g[r][c][2] ? 1 + d[r][c-1][2] : 0;
        }
        for (int c = 1; c <= n; ++c) {
            for (int r = 2; r <= n; ++r)
                d[r][c][1] = g[r][c][1] ? 1 + d[r-1][c][1] : 0;
            for (int r = n - 1; r >= 1; --r)
                d[r][c][3] = g[r][c][3] ? 1 + d[r+1][c][3] : 0;
        }

        for (int r = 1; r < n; ++r)
            for (int c = 1; c < n; ++c)
                for (int i = min(d[r][c][0], d[r][c][3]); i > 0; --i)
                    if (d[r + i][c + i][1] >= i && d[r + i][c + i][2] >= i)
                        ++ans[i];

        if (kase)
            puts("\n**********************************\n");
        printf("Problem #%d\n\n", ++kase);
        bool ok = false;
        for (int i = 1; i <= n; ++i)
            if (ans[i]) {
                ok = true;
                printf("%d square (s) of size %d\n", ans[i], i);
            }
        if (!ok)
            puts("No completed squares can be found.");
    }
}
