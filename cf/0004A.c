#include <stdio.h>
int main()
{
    int w;
    while (scanf("%d", &w) == 1) {
        if (w == 2 || (w & 1))
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
