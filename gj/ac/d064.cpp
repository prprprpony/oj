#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(char *a, char *b)
{
    int i;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++)
        if (a[i] != b[i])
            return a[i] > b[i];
    if (a[i] == b[i])
        return true;
    else if (a[i] == '\0')
        return cmp(a, b+i);
    else
        return cmp(a+i, b);
}

int main()
{
    char n[3][100];
    char *num[3];
    for (int i = 0 ; i < 3; i++) {
        scanf("%s", n[i]);
        num[i] = n[i];
    }
    sort(num, num+3, cmp);
    for (int i = 0 ; i < 3; i++)
        fputs(num[i], stdout);
    putchar('\n');

    return 0;
}
