#include <stdio.h>
int main()
{
    int c, n = 0;
    while ((c = getchar()) != EOF)
        if (c != '"')
            putchar(c);
        else
            fputs(((n = !n) ? "``" : "''"), stdout);
    return 0;
}
