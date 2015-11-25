#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n / 11 * 1000 + n % 11 * 100);
    return 0;
}
