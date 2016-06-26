#include <stdio.h>
#include <stdlib.h>
#define MAXN 50
char buf[MAXN][MAXN];
char* a[MAXN];

int cmp(const void* x, const void* y) {
    char *X = *(char**)x;
    char *Y = *(char**)y;
    int i;
    while (1) {
        for (i = 0; X[i] != '\0' && Y[i] != '\0'; i++)
            if (X[i] != Y[i])
                return Y[i] - X[i];
        if (X[i] == Y[i]) { /* both are '\0' */
            return 0;
        } else {
            if (X[i] == '\0')
                Y += i;
            else
                X += i;
        }
    }
}

int main()
{
    int n;
    int i;
    while (scanf("%d", &n) == 1 && n) {
        for (i = 0; i < n; i++) {
            scanf("%s", buf[i]);
            a[i] = buf[i];
        }
        qsort(a, n, sizeof(char*), cmp);
        for (i = 0; i < n ; i++)
            fputs(a[i], stdout);
        putchar('\n');
    }
    return 0;
}
