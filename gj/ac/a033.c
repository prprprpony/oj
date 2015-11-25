#include <stdio.h>

int main()
{
    int n;
    int i;
    char s[11] = "|________|";

    scanf("%d", &n);

    for (i = 8; n && i >= 5; n /= 10, i--)
        s[i] = n % 10 + '0';

    puts(s);

    return 0;
}
