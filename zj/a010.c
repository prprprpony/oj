#include <stdio.h>
#define MAXN 1000000
int main()
{
    int n;
    int i;
    int f[MAXN], p[MAXN];
    int top;
    while (scanf("%d", &n) == 1) {
        top = 0;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                f[top] = i;
                p[top] = 0;
                while (n % i == 0) {
                    n /= i;
                    p[top]++;
                }
                top++;
            }
        }

        if (n != 1) {
            f[top] = n;
            p[top++] = 1;
        }

        for (i = 0; i < top; i++) {
            if (i)
                printf(" * ");
            printf("%d", f[i]);
            if (p[i] > 1)
                printf("^%d", p[i]);
        }
        putchar('\n');
    }
    return 0;
}
