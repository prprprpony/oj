#include <stdio.h>
int main()
{
    int n, ans = 1;
    scanf("%d", &n);
    while (n--) {
        ans *= 13;
        ans %= 100;
    }
    printf("%d\n", ans / 10);
    return 0;
}
