#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int maxd;
int H(int p[], int n)
{
    int num = 0;
    int i;
    for (i = 1; i < n; ++i)
        if ((p[i-1]+1) != p[i])
            num++;
    return num;
}

bool dfs(int d, int p[], int n)
{
    if (d == maxd)
        return false;
    if (3 * (maxd-d) < H(p, n))
        return false;
    int i, j, k;
    for (i = 0; i < n; ++i)
        for (j = i; j < n; ++j) {
            int size = j-i+1;
            int left = n - size;
            int sp[size];
            memcpy(sp, &p[i], size * sizeof(int));
            for (k = i; k + size < n; ++k)
                p[k] = p[k+size];
            for (k = 0; k < left; ++k) {
                memmove(&p[k+size], &p[k], (left-k) * sizeof(int));
                memcpy(&p[k], sp, size * sizeof(int));
                dfs(d+1, p, n);
// <= to be continued
            }
        }
}

int main(void)
{
    int n;
    int case_num = 1;
    int i;
    while (scanf("%d", &n) != EOF && n > 1) {
        int p[n];
        for (i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
        }
        for (maxd = 1; maxd < n; ++maxd) {
            if (dfs(0, p, n))
                break;
        }

        printf("Case %d: %d\n", case_num++, maxd);
    }
    return 0;
}
