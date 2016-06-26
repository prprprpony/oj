#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int i, j;
    char c;
    char b[50][50];
    for (i = 0, c = 'a'; i < 50; ++i, c = (c == 'z')?'A':(c+1))
        memset(b[i], c, 50);
    while (scanf("%d", &n) == 1) {
        printf("%d %d %d\n", 2, n, n);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j)
                putchar(b[i][j]);
            putchar('\n');
        }
        putchar('\n');
        for (j = 0; j < n; ++j) {
            for (i = 0; i < n; ++i)
                putchar(b[i][j]);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
