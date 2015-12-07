#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10;
int matrix[maxn][maxn];
int row[maxn];
int col[maxn];
char op[15];
bool transposed;
int delta;
int main()
{
    int t, n, m, a, b;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d ", &n);
        transposed = false;
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
                    transposed = !transposed;
                    break;
                default:
                    scanf("%d%d", &a, &b);
                    if ((op[0] == 'r') == !transposed)
                        swap(row[a], row[b]);
                    else
                        swap(col[a], col[b]);
                    break;
            }
        }
        printf("Case #%d\n", kase);
        if (!transposed) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++)
                    putchar((matrix[row[i]][col[j]] + delta) % 10 + '0');
                putchar('\n');
            }
        } else {
            for (int j = 1; j <= n; j++) {
                for (int i = 1; i <= n; i++)
                    putchar((matrix[row[i]][col[j]] + delta) % 10 + '0');
                putchar('\n');
            }
        }
        putchar('\n');
    }
    return 0;
}
