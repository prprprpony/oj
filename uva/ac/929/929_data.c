#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *f = fopen("929_data", "w");
    srand(time(NULL));
    int t = 1;
    int n = 999;
    int m = 999;
    int i, j;
    char buf[5000000];
    char *b = buf;
    b += sprintf(b, "%d\n", t);
    while (t--) {
        b += sprintf(b, "%d\n", n);
        b += sprintf(b, "%d\n", m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                b += sprintf(b, "%d ", rand() % 10);
            b += sprintf(b, "\n");
        }
    }
    fputs(buf, f);
    return 0;
}
