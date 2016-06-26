#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 104;
int a[2][maxn];
int main()
{
    int n, d, r;
    while (scanf("%d%d%d", &n, &d, &r) == 3 && n) {
        for (int b = 0; b <= 1; ++b)
            for (int i = 0; i < n; ++i)
                scanf("%d", a[b] + i);
        sort(a[0], a[0] + n);
        sort(a[1], a[1] + n, greater<int>());
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (a[0][i] + a[1][i] > d)
                ans += (a[0][i] + a[1][i] - d) * r;
        printf("%d\n", ans);
    }
}
