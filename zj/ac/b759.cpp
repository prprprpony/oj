#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e3 + 228;
char s[maxn];
int main()
{
    fgets(s, sizeof(s), stdin);
    int len = strlen(s) - 1;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j)
            putchar(s[(i + j) % len]);
        putchar('\n');
    }
}
