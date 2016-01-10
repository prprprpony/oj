#include <stdio.h>
int main()
{
    long long n, t;
    while (scanf("%lld", &n) == 1 && n > 0) {
        while (n > 9) {
            t = 0;
            while (n > 0) {
                t += n % 10;
                n /= 10;
            }
            n = t;
        }
        printf("%lld\n", n);
    }
    return 0;
}
