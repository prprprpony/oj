#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 48763;
int a[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        sort(a, a + n, [=] (int a, int b) -> bool {return abs(a) < abs(b);});
        int ans = 1;
        for (int i = 1; i < n; ++i)
            if ((a[i-1] > 0) != (a[i] > 0))
                ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
