#include <stdio.h>
int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}
int main()
{
    int n, m, i;
    int c, mn, mx;
    scanf("%d%d", &n, &m);
    mx = 0;
    while (n--) {
        i = m;
        mn = 1000000000 + 42;
        while (i--) {
            scanf("%d", &c);
            mn = min(mn, c);
        }
        mx = max(mx, mn);
    }
    printf("%d\n", mx);

    return 0;
}
