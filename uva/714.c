#include <stdio.h>
#include <string.h>
int p[550];
char slash[550];
int m, k;

int max(int a, int b)
{
    return a > b ? a : b;
}

int max_part(long long x)
{
    int i;
    int b;
    long long s;
    for (s = 0, i = 0, b = 0; i < m; i++) {
        s += p[i];
        if (s > x) {
            b++;
            s = p[i];
        }
    }
#ifdef DEBUG
printf("x = %lld, b = %d\n", x, b);
#endif
    return b <= k - 1;
}

int main()
{
    int n;
    int i;
    long long high;
    long long low;
    long long mid;
    long long s;

    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &m, &k);
        for (high = 0, low = 0, i = 0; i < m; i++) {
            scanf("%d", &p[i]);
            high += p[i];
            low = max(low, p[i]);
        }
        memset(slash, 0, m * sizeof(char));

        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (max_part(mid))
                high = mid;
            else
                low = mid + 1;
        }
#ifdef DEBUG
printf("low = %lld\n", low);
#endif
        for (s = p[m - 1], i = m - 2, k = k - 1; i >= 0; i--) {
            s += p[i];
            if (k && (s > low || i + 1 == k)) {
                slash[i] = 1;
                s = p[i];
                k--;
            }
        }

        for (i = 0; i < m; i++) {
            printf("%d", p[i]);
            putchar(i == m-1 ? '\n' : ' ');
            if (slash[i])
                printf("/ ");
        }
    }

    return 0;
}
