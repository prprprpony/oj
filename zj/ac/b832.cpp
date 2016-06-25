#include <cstdio>
using namespace std;
const int maxn = 1.1e7;
int a[maxn];
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        scanf("%d", a + i);
    int low, high;
    scanf("%d%d", &high, &low);
    int ans = 0;
    for (int i = 0; i < t; ++i)
        if (low <= a[i] && a[i] <= high)
            ++ans;
    printf("%d\n", ans);
    return 0;
}
