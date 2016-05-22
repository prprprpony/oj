#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAXN 100000
#define M 1000001
int main()
{
    int i, j;
    int l, r, t;

    srand(time(NULL));
    printf("%d\n", MAXN);
    for (i = 0; i < MAXN; i++) {
        for (j = 0; j < 2; j++) {
            l = rand() % M;
            while ((r = rand() % M) == l);
            if (l > r) {
                t = r;
                r = l;
                l = t;
            }
            printf("%d %d ", l, r);
        }
        putchar('\n');
    }
    return 0;
}
