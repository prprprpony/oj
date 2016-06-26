#include <cstdio>
using namespace std;
const int maxn = 1.228e5;
int a[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    int ans = 0;
    int l = 0,  r = n - 1;
    int pre = 0, post = 0;
    for ( ; l < n; ++l) {
        pre += a[l];
        while (post < pre && r >= 0)
            post += a[r--];
        if (post == pre)
            ++ans;
    }
    printf("%d\n", ans);
}
