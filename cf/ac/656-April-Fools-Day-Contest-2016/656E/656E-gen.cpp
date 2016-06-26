#include <cstdio>
using namespace std;
const int maxn = 10;
int main()
{
    fputs(
            "#include <cstdio>\n"
            "#include <algorithm>\n"
            "using namespace std;"
            "int d[10][10];"
            "int main()"
            "{"
            "int n;"
            "scanf(\"\%d\", &n);",
            stdout);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            printf("%d < n && %d < n ? scanf(\"%cd\", &d[%d][%d]) : d[%d][%d] = 1024;",
                    i,        j,               '%',       i,   j,       i,  j);
    for (int k = 0; k < maxn; k++)
        for (int i = 0; i < maxn - 1; i++)
            for (int j = i + 1; j < maxn; j++)
                printf("d[%d][%d] = d[%d][%d] = min(d[%d][%d], d[%d][%d] + d[%d][%d]);",
                        i,  j,      j,  i,          i,  j,     i,  k,      k,   j);
    fputs("int ans = d[0][1];", stdout);
    for (int i = 0; i < maxn - 1; i++)
        for (int j = i + 1; j < maxn; j++)
            printf("%d < n ? ans = max(ans, d[%d][%d]) : 0;", j, i, j);
    fputs(
            "printf(\"\%d\\n\", ans);"
            "return 0;"
            "}",
            stdout);
    return 0;
}
