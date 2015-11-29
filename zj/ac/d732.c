#include <stdio.h>
#define MAXN 100000
int main()
{
    int n, k, i;
    int a[MAXN];
    int x, low, mid, high;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", a + i);
    for (i = 0; i < k; i++) {
        scanf("%d", &x);
        low = 0;
        high = n - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (a[mid] >= x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        printf("%d\n", a[low] == x ? low + 1 : 0);
    }
    return 0;
}
