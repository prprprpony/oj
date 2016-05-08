#include <cstdio>
#include <cstring>
using namespace std;
char s[2][42];
int main()
{
    int t;
    scanf("%d ", &t);
    for (int kase = 1; kase <= t; ++kase) {
        printf("Case %d: ", kase);
        fgets(s[0], sizeof(s[0]), stdin);
        fgets(s[1], sizeof(s[1]), stdin);
        if (!strcmp(s[0], s[1])) {
            puts("Yes");
        } else {
            bool wa = false;
            for (int i = 0, j = 0; !wa && (s[1][j] || s[0][i]); ++i, ++j) {
                while (s[0][i] == ' ')
                    ++i;
                wa = s[0][i] != s[1][j];
            }
            puts(wa ? "Wrong Answer" : "Output Format Error");
        }
    }
    return 0;
}
