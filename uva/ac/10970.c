#include <stdio.h>
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
        printf("%d\n", m * n - 1);
    return 0;
}
