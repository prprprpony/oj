#include <stdio.h>
#include <ctype.h>
char n[2][1000005];
char *s[2];
char *e[2];
int i;
int main(void)
{
    for (i = 0; i < 2; i++) {
        fgets(n[i], sizeof(n[i]), stdin);
        s[i] = n[i];
        while (*s[i] == '0')
            s[i]++;
        e[i] = s[i];
        while (isdigit(*e[i]))
            e[i]++;
    }
    if (e[0] - s[0] != e[1] - s[1]) {
        putchar(e[0] - s[0] > e[1] - s[1] ? '>' : '<');
    } else {
        for ( ; s[0] < e[0]; s[0]++, s[1]++) {
            if (*s[0] != * s[1]) {
                putchar(*s[0] > *s[1] ? '>' : '<');
                goto newline;
            }
        }
        putchar('=');
    }
newline:
    putchar('\n');
    return 0;
}
