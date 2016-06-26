#include <cstdio>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = (((n + 1) / 2) + m - 1) / m * m;
    printf("%d\n", ans > n ? -1 : ans);
}
