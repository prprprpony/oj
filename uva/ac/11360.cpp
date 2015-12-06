#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10;
int matrix[maxn][maxn];
int row[maxn];
int col[maxn];
int *r;
int *c;
char op[15];
int delta;
int main()
{
    int t, n, m, a, b;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d ", &n);
        r = row;
        c = col;
        delta = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                matrix[i][j] = getchar() - '0';
            while (getchar() != '\n');
            row[i] = col[i] = i;
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%s", op);
            switch (op[0]) {
                case 'i':
                    delta = (delta + 1) % 10;
                    break;
                case 'd':
                    delta = (delta + 9) % 10;
                    break;
                case 't':
                    swap(r, c);
                    break;
                default:
                    scanf("%d%d", &a, &b);
                    if (op[0] == 'r')
                        swap(r[a], r[b]);
                    else
                        swap(c[a], c[b]);
                    break;
            }
        }
        printf("Case #%d\n", kase);
        if (r == row) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++)
                    putchar((matrix[r[i]][c[j]] + delta) % 10 + '0');
                putchar('\n');
            }
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++)
                    putchar((matrix[c[j]][r[i]] + delta) % 10 + '0');
                putchar('\n');
            }
        }
        putchar('\n');
    }
    return 0;
}
