#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const char ch[] = "IVXLCDM";
const int val[] = {1, 5, 10, 50, 100, 500, 1000};

int getid(char c)
{
    for (int i = 0; ch[i]; ++i)
        if (ch[i] == c)
            return i;
    return -1;
}

int value(char * s)
{
    int ret = 0;
    int pre = getid(s[0]);
    for (int i = 1; s[i]; ++i)
    {
        int j = getid(s[i]);
        ret += (j <= pre ? 1 : -1) * val[pre];
        pre = j;
    }
    return ret + val[pre];
}

char * toRoman(int v, char * s)
{
    int j = 0;
    for (int i = sizeof(val) / sizeof(int) - 1; i >= 0; --i)
    {
        for ( ; v >= val[i]; v -= val[i])
            s[j++] = ch[i];
    }
    for (int i = 3; i < j; ++i)
        if (s[i] == s[i - 3]) {
            s[i - 2] = ch[getid(s[i]) + 1];
            memmove(s + i - 1, s + i + 1, j - i);
            j -= 2;
            i -= 2;
            if (i > 1 && s[i] == s[i - 2]) {
                s[i] = ch[getid(s[i]) + 1];
                memmove(s + i - 2, s + i - 1, j - i + 1);
                --j;
                --i;
            }
        }
    s[j] = '\0';
    return s;
}

int main()
{
    char a[50], b[50], c[50];
    while (scanf("%s%s", a, b) == 2 && a[0] != '#') {
#ifdef PP
        printf("%d %d\n", value(a), value(b));
#endif
        int d = abs(value(a) - value(b));
        puts(d ? toRoman(d, c) : "ZERO");
    }
}
