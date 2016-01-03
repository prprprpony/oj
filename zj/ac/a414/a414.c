#include <stdio.h>
int main()
{
    int n, i;
    while (scanf("%d", &n) == 1 && n) {
        for (i = 0; (1 << i) & n; i++);
        printf("%d\n", i);
    }
    return 0;
}
