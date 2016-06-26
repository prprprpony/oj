#include <stdio.h>
#define MAXP 31
int main()
{
    int one[MAXP];
    int i;
    int low, mid, high;
    int n;
    for (one[0] = i = 1; i < MAXP; i++)
        one[i] = one[i - 1] | (1 << i);
    while (scanf("%d", &n) == 1 && n > 0) {
        low = 0;
        high = MAXP - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if ((one[mid] & n) == one[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        printf("%d\n", low);
    }
    return 0;
}
