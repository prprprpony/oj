#include <cstdio>
using namespace std;
const int maxn = 200 + 5;
char g[maxn][maxn];
int rows;
int cols[maxn];
void dfs(int r, int c)
{
    printf("%c(", g[r][c]);
    if (r + 3 < rows && c < cols[r + 1] && g[r + 1][c] == '|') {
        int left, right;
        for (left = c; left > 0; ) {
            if(g[r + 2][left - 1] == '-')
                left--;
            else
                break;
        };
        for (right = c; right + 1 < cols[r + 2]; ) {
            if (g[r + 2][right + 1] == '-')
                right++;
            else
                break;
        }
        for (int i = left;  i < cols[r + 3] && i <= right; i++)
            if (g[r + 3][i] != ' ')
                dfs(r + 3, i);
    }

    putchar(')');
}

int main()
{
    int t;
    scanf("%d", &t);
    while (getchar() != '\n');
    while (t--) {
        for (rows = 0; ; rows++) {
            g[rows][0] = getchar();
            if (g[rows][0] == '#') {
                while (getchar() != '\n');
                break;
            } else if (g[rows][0] == '\n') {
                cols[rows] = 1;
                continue;
            }
            for (cols[rows] = 1; ; cols[rows]++) {
                g[rows][cols[rows]] = getchar();
                if (g[rows][cols[rows]] == '\n')
                    break;
            }
        }
        putchar('(');
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols[r]; c++)
                if (g[r][c] != ' ' && g[r][c] != '\n') {
                    dfs(r,c);
                    goto ans;
                }
    ans:
        putchar(')');
        putchar('\n');
    }
    return 0;
}
