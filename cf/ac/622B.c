#include <stdio.h>
int main()
{
    int h, m, a;
    scanf("%d:%d %d", &h, &m, &a);
    m += a % 60;
    h += a / 60;
    h += m / 60;
    m %= 60;
    h %= 24;
    printf("%02d:%02d\n", h, m);
    return 0;
}
