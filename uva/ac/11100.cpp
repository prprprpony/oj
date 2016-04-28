#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 1e4 + 486;
int a[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n) {
        static bool first = true;
        if (!first)
            putchar('\n');
        else
            first = false;

        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        sort(a, a + n);
        int d = 1;
        for (int i = 1, cnt = 1; i < n; ++i) {
            cnt = a[i] == a[i-1] ? cnt + 1 : 1;
            d = max(d, cnt);
        }
        printf("%d\n", d);
        for (int i = 0; i < d; ++i) {
            printf("%d", a[i]);
            for (int j = i + d; j < n; j += d)
                printf(" %d", a[j]);
            putchar('\n');
        }
    }
    return 0;
}
