#include <cstdio>
#define MAXN (int)2e5 + 42
using namespace std;
int a[MAXN];
int p[MAXN]; // p[i] = the first j from i to 1 such that a[j] != a[i]
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    p[1] = -1;
    for (int i = 2; i <= n; i++)
        if (a[i-1] != a[i])
            p[i] = i - 1;
        else
            p[i] = p[i-1];
    while (m--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        printf("%d\n", a[r] != x ? r : (p[r] >= l ? p[r] : -1));
    }

    return 0;
}
