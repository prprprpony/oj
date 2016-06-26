#include <stdio.h>
long long find(int a, int b)
{
    if (a > b) 
        return (a % b) ? (1 + find(b, a % b)) << (a / b) : 1LL << (a / b - 1);
    else if (a < b)
        return 1 + find(b, a);
    else
        return 1;
}

int main(void)
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) 
        printf("%lld\n", find(a, b));
    return 0;
}
