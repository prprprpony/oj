#include <stdio.h>

int main()
{
    int n, i, j;
    while (scanf("%d", &n) == 1) {
        for (i = 1 << ((sizeof(int) << 3) - 2); i != 0; i >>= 1) {
            if (n & i)
                break;
        }
        do {
            putchar((n & i) ? '1' : '0');
            i >>= 1;
        } while(i);
        putchar('\n');
    }

    return 0;
}
