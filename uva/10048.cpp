#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110;
int g[maxn][maxn];
int main()
{
    int c, s, q;
    int a, b, d;
    int kase = 0;
    while (scanf("%d%d%d", &c, &s, &q) == 3 && c) {
        memset(g, -1, sizeof(g));
        while (s--) {
            scanf("%d%d%d", &a, &b, &d);
            g[a][b] = g[b][a] = d;
        }
        for (int k = 1; k <= c; k++)
            for (int i = 1; i <= c; i++)
                for (int j = 1; j <= c; j++)
                    if (g[i][k] != -1 && g[k][j] != -1) {
                        if (g[i][j] != -1)
                            g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
                        else
                            g[i][j] = max(g[i][k], g[k][j]);
                    }
        if (kase)
            putchar('\n');
        printf("Case #%d\n", ++kase);
        while (q--) {
            scanf("%d%d", &a, &b);
            if (g[a][b] != -1)
                printf("%d\n", g[a][b]);
            else
                puts("no path");
        }
    }
    return 0;
}
