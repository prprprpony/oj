#include <stdio.h>
int main(void)
{
    int n, i, kase = 0;
    while (scanf("%d", &n) == 1 && n > 0) {
        for (i = 0; (1 << i) < n; ++i);
        printf("Case %d: %d\n", ++kase, i);
    }
    return 0;
}
