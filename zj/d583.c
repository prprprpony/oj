#include <stdio.h>
int main()
{
    int n, i;
    while (scanf("%d ", &n) == 1) {
        while (getchar() != '\n');
        putchar('1');
        for (i = 2; i <= n; ++i)
            printf(" %d", i);
        putchar('\n');
    }
}
