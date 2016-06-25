#include <cstdio>
#include <climits>
using namespace std;
void dfs(int x)
{
    if (x > 2) {
        int i;
        for (i = sizeof(int) * CHAR_BIT - 1; i >= 0 && x; --i)
            if (x & (1 << i)) {
                x ^= (1 << i);
                if (i > 1) {
                    fputs("2(", stdout);
                    dfs(i);
                    putchar(')');
                } else  {
                    dfs(1 << i);
                }
                if (x)
                    putchar('+');
            }
    } else if (x == 2) {
        putchar('2');
    } else if (x == 1) {
        fputs("2(0)", stdout);
    } else {
        putchar('0');
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        dfs(n);
        putchar('\n');
    }
}

