#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int min(int a, int b)
{
    return a < b ? a : b;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
const int coin[6] = {1, 5, 10, 12, 16, 20};
int main()
{
    int n, i, j;
    int *d = NULL;
    int len = 0;
    while (scanf("%d", &n) == 1) {
        if (n + 1 > len) {
            d = (int *)realloc(d, (n + 1) * sizeof(int));
            memset(d + len + 1, 0, (n + 1 - len) * sizeof(int));
            for (i = 0; i < sizeof(coin) / sizeof(int); i++) {
                for (j = max(len + 1, coin[i]); j <= n; j++) {
                    if (j - coin[i] == 0 || ((j - coin[i] > 0) && d[j-coin[i]])) {
                        if (d[j])
                            d[j] = min(d[j], d[j-coin[i]] + 1);
                        else
                            d[j] = d[j-coin[i]] + 1;
                    }
                }
            }
            len = n + 1;
        }
        printf("%d\n", d[n]);
    }

    return 0;
}
