#include <stdio.h>
int gcd(int a, int b) {return b != 0 ? gcd(b, a % b) : a;}
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2)
        printf("%d\n", gcd(a, b));
    return 0;
}
