#include <cstdio>
#define MAXN 100
#define CENT 50
using namespace std;
int main()
{
    int s[MAXN][MAXN];
    
    for (int num = 0, l = 0; l < 50; ++l) {
        int r, c;
        for (r = CENT + l - 1, c = CENT + l; r > CENT - l; r--)
            s[r][c] = num++;
        for (; c > CENT - l; c--)
            s[r][c] = num++;
        for (; r < CENT + l; r++)
            s[r][c] = num++;
        for (; c <= CENT + l; c++)
            s[r][c] = num++;
    }

    int t;
    int n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        n = (n-1)>>1;
        for (int r = CENT - n; r <= CENT + n; r++)
            for (int c = CENT - n; c <= CENT + n; c++) {
                printf("%4d", s[r][c]);
                putchar((c != CENT + n) ? ' ' : '\n');
            }
    }

    return 0;
}
