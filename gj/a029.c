#include <stdio.h>
int a, b, i;
int main()
{
    scanf("%d%d", &a, &b);
    for (i = a; i <= b; i++)
        printf("%d%c", i, i != b ? '+' : '=');
    printf("%d\n", (a + b) * (b - a + 1) / 2);
    return 0;
}
