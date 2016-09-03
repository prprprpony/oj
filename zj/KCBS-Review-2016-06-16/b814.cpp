#include <cstdio>
using namespace std;
const int maxn = 1e5 + 228;
int p[maxn];
int main(void)
{
    int c, lc, n = 1;
    lc = getchar();
    while ((c = getchar()) != '\n') {
        p[n] = (c == lc ? 1 : 0) + p[n - 1];
        ++n;
        lc = c;
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", p[r - 1] - p[l - 1]);
    }
    return 0;
}
