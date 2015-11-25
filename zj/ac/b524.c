#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, c, j, m;
    for (i = 0, j = 0, m = 0, c = getchar(); c != EOF; i++, c = getchar())
        switch (c) {
        case 'y':
            m += abs(i-j);
            j += 3;
            break;
        case '\n':
            printf("%d\n", m);
            i = -1;
            j = 0;
            m = 0;
            break;
        }
    if (i != 0)
        printf("%d\n", m);
    return 0;
}
