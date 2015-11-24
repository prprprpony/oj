#include <cstdio>
#include <algorithm>
using namespace std;
int main(void)
{
    int n, m, i, j, cost;
    while(scanf("%d%d", &n, &m) == 2 && n) {
        if (m < n) {
            for (i = 0; i < n + m; ++i)
                scanf("%*d");
            printf("Loowater is doomed!\n");
            continue;
        }
        int d[n];
        int k[m];
        for (i = 0; i < n; ++i)
            scanf("%d", &d[i]);
        for (i = 0; i < m; ++i)
            scanf("%d", &k[i]);
        sort(d, d + n);
        sort(k, k + m);
        for (cost = 0, j = 0, i = 0; i < n; ++i) {
            while (k[j] < d[i] && j < m)
                ++j;
            if (j < m)
                cost += k[j++];
            else
                break;
        }
        if (i != n)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", cost);
    }
    return 0;
}
